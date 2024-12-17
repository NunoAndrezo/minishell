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

# SRC directories
BUILTINS_DIR = $(SRC_DIR)/builtins
PARSING_DIR = $(SRC_DIR)/parsing
EXEC_DIR = $(SRC_DIR)/exec
UTILS_DIR = $(SRC_DIR)/utils
ENV_DIR = $(SRC_DIR)/env
SIGNALS_DIR = $(SRC_DIR)/signals
HISTORY_DIR = $(SRC_DIR)/history
HERE_DOC_DIR = $(SRC_DIR)/here_doc
EXPANSIONS_DIR = $(SRC_DIR)/expansions
PATHS_DIR = $(SRC_DIR)/path
REDIRECTION_DIR = $(SRC_DIR)/redirection

# Rule to build the included library
LIBS = $(LIB_DIR)/libft.a

# Source and bonus files
SRC_FILES = $(find $(SRC_DIR) -name "*.c")
BONUS_FILES = $(find $(SRC_DIR) -name "*_bonus.c")

# Object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Object files
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

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
	@$(eval COMPILED_FILES=$(words $(OBJ_FILES:$(OBJ_DIR)/%.o=$(OBJ_DIR)/%.o)))
	@$(CC) $(CFLAGS) $(POSTCC) -c $< -o $@
	@$(call print_bar,$(COMPILED_FILES))

# Rule to compile the included library
$(LIBS):
	@make -C $(LIB_DIR) #> /dev/null 2>&1
	@echo "$(GREEN)Library built successfully.$(NOCOLOR)"

# Rule to compile the project
$(NAME): $(OBJ_DIR) $(OBJ_FILES) 
	@echo "$(YELLOW)Building project...$(NOCOLOR)"
	@$(CC) $(CFLAGS) $(POSTCC) $(OBJ_FILES) -o $(NAME) $(LIBS)
	@echo "$(GREEN)Project built successfully.$(NOCOLOR)"

# build only the library
libs: $(LIBS)

# build the project
build: $(LIBS) $(NAME)

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

