# build all
all: libs build bonus

# Colors
GREEN = \033[0;32m
RED = \033[0;31m
CYAN = \033[0;36m
BLUE = \033[0;34m
YELLOW = \033[0;33m
NOCOLOR = \033[0m

# Name of the project
NAME = minishell 

# Compiler
CC = cc

# Flags
CFLAGS = -Wall -Wextra -Werror -g 
POSTCC = -I $(INC_DIR) -I $(LIB_DIR) 

# Directories
SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc
LIB_DIR = $(INC_DIR)/lib_ft

# Object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Rule to build the included library
LIBS = $(LIB_DIR)/libft.a

# Source and bonus files
SRC_FILES = $(shell find $(SRC_DIR) -type f -name "*.c")

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Total number of files and bar length
TOTAL_FILES := $(words $(SRC_FILES))
BAR_SYMBOL := ▓

# Function to print the loading bar incrementally
define print_bar
	@CURRENT_PROGRESS=$$(( $(1) * 50 / $(TOTAL_FILES) )); \
	echo -n $(CYAN); \
	for i in $$(seq 1 $$CURRENT_PROGRESS); do echo -n $(BAR_SYMBOL); done; \
	echo -n $(NOCOLOR)
endef

# Rule to compile .c into .o with progress bar
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(POSTCC) -c $< -o $@
	@$(call print_bar, $(words $(OBJ_FILES)))
	@echo -n " $(GREEN)[$(words $(OBJ_FILES))/$(TOTAL_FILES)]$(NOCOLOR) Compiling $<\r"

# Rule to compile the included library
$(LIBS):
	@make -C $(LIB_DIR) #> /dev/null 2>&1
	@echo "$(GREEN)Library built successfully.$(NOCOLOR)"

# Rule to compile the project
$(NAME): $(OBJ_DIR) $(OBJ_FILES)
	@echo "$(YELLOW)Building project...$(NOCOLOR)"
	@$(CC) $(CFLAGS) $(POSTCC) $(OBJ_FILES) -lreadline -L$(LIB_DIR) -lft -o $(NAME)
	@echo "$(GREEN)Project built successfully.$(NOCOLOR)"

# build only the library
libs: $(LIBS)

# build the project
build: $(NAME)

# clean the object files
clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_DIR) > /dev/null 2>&1
	@echo "$(BLUE)Object files removed.$(NOCOLOR)"
	@echo "$(GREEN)Clean done.$(NOCOLOR)"

# clean the object files and the project
fclean: clean
	@rm -f $(NAME) $(BONUS)
	@make fclean -C $(LIB_DIR) > /dev/null 2>&1
	@echo "$(BLUE)Project removed.$(NOCOLOR)"
	@echo "$(GREEN)Full clean done.$(NOCOLOR)"

# clean and rebuild the project
re: fclean all

# run the project
run: build
	@./$(NAME)

.PHONY: all clean fclean re run libs build bonus
