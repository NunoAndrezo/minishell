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
POSTCC = -I $(INC_DIR) -I $(LIB_DIR) -L/usr/lib/x86_64-linux-gnu -L/usr/lib -lreadline -lncurses

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
SRC_FILES = ./src/env/add_env_vars.c ./src/env/copy_env.c ./src/env/copy_env_2.c ./src/env/sort_env.c ./src/run/run_shell_2.c ./src/run/run_cmds.c ./src/run/run_builtins.c ./src/run/run_no_pipe.c ./src/run/run_shell.c ./src/run/exec_handler.c ./src/cmd_as_regular_user/dollar_sign_command.c ./src/cmd_as_regular_user/dollar_sign_command2.c ./src/cmd_as_regular_user/dollar_sign_here_doc.c ./src/pipes/close_pipes.c ./src/pipes/close_pipes_2.c ./src/pipes/pipes.c ./src/frees/exit_1.c ./src/frees/exit_2.c ./src/signals/signal.c ./src/main.c ./src/builtins/env.c ./src/builtins/exit.c ./src/builtins/external_cmd.c ./src/builtins/cd.c ./src/builtins/pwd.c ./src/builtins/export.c ./src/builtins/unset.c ./src/builtins/echo.c ./src/inits/init_shell.c ./src/utils/remove_quotes.c ./src/utils/strip_quotes.c ./src/utils/ft_realloc_arr.c ./src/utils/newline.c ./src/utils/str_replace_segment.c ./src/utils/ft_get_pid.c ./src/utils/ft_strstr.c ./src/utils/copy_array.c ./src/utils/ft_is_space.c ./src/utils/ft_str_r_cmp.c ./src/utils/ft_strcat.c ./src/utils/malloc_failure.c ./src/redirections/handle_redirections.c ./src/redirections/ft_here_doc.c ./src/redirections/redir_exe.c ./src/redirections/close_redirs.c ./src/redirections/hd_expansions.c ./src/debugging/debug_1.c ./src/debugging/debug_2.c ./src/parsing/constructor_2.c ./src/parsing/constructor_6.c ./src/parsing/constructor_3.c ./src/parsing/constructor_1.c ./src/parsing/constructor_4.c ./src/parsing/constructor_5.c ./src/parsing/copy_valid_args.c ./src/parsing/constructor_7.c ./src/parsing/marking_pipes.c ./src/parsing/parse_cmd.c ./src/parsing/parse_split.c ./src/parsing/parsing_1.c ./src/parsing/parsing_2.c ./src/parsing/parsing_3.c ./src/parsing/redir_assign.c ./src/parsing/redir_constructor.c ./src/parsing/redir_counts.c ./src/parsing/redir_counts_2.c ./src/parsing/redirection_parsing.c ./src/parsing/redirection_split.c ./src/parsing/tokenizer.c ./src/validations/command_checker.c ./src/validations/validations.c ./src/wildcards/ft_wildcard_expand.c ./src/wildcards/ft_wildcard_expand2.c ./src/wildcards/ft_wildcard_pattern.c ./src/wildcards/ft_wildcard.c ./src/wildcards/ft_wildcard_helpers.c ./src/wildcards/ft_wildcard_pattern2.c ./src/wildcards/ft_wildcard_utils.c

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES)) 

# Total number of files and bar length
TOTAL_FILES := $(words $(SRC_FILES))
BAR_SYMBOL := ▓
BAR_LENGTH := 50
PROGRESS := 0

# Rule to compile .c into .o with progress bar
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)  # Create the directory if it doesn't exist
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval PROGRESS := $(shell echo $$(($(PROGRESS) + 1))))
	@$(eval PERCENT := $(shell echo $$(($(PROGRESS) * 100 / $(TOTAL_FILES)))))
	@$(eval BAR := $(shell echo $$(($(PROGRESS) * $(BAR_LENGTH) / $(TOTAL_FILES)))))
	@$(eval REST := $(shell echo $$(($(BAR_LENGTH) - $(BAR)))))
	@echo -n "\r\033[K"  # Clear the line
	@echo -n "$(CYAN)["  # Start the bar

	@for i in `seq 1 $(BAR)`; do \
		echo -n $(BAR_SYMBOL); \
	done


	@echo -n "] $(PERCENT)% $(RED)Compiling:$(NOCOLOR) $<"
#	@sleep 0.1  # Just to make the bar smooth

# Rule to compile the included library
$(LIBS):
	@make -C $(LIB_DIR) #> /dev/null 2>&1
	@echo "$(GREEN)Library built successfully.$(NOCOLOR)"

# Rule to compile the project
$(NAME): $(OBJ_FILES)
	@echo ""
	@echo "$(YELLOW)Creating $(NAME)..."
	@$(CC) $(CFLAGS) $(POSTCC) $(OBJ_FILES) -o $(NAME) -L/usr/lib/x86_64-linux-gnu -lreadline -lncurses $(LIBS)
	@sleep 0.2 # Just to let the loading bar finish smoothly
	@echo -n "\r\033[K" # Erase the loading bar
	@echo "$(GREEN)$(NAME) created successfully.$(NOCOLOR)"

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
