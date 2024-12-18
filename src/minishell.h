/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:01:28 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/18 22:24:20 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../inc/lib_ft/ft_printf.h"
# include "../inc/lib_ft/get_next_line.h"
# include "../inc/lib_ft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define monke "\U0001F648"

# define PROMPT monke " minishell _$ "
# define PROMPT_SIZE 11

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"

# define HERE_DOC "here_doc"
# define HD_TEMP_FILE ".hd_temp"
# define HISTORY ".minishell_history"

// struct to store the here document information
typedef struct here_doc
{
	char *delim;   // delimiter of the here document
	char *content; // content of the here document
	char *file;    // file to store the here document

	int fd; // file descriptor
}				t_here_doc;

// struct to store the redirection information
typedef struct redir
{
	char *input;    // input redirection
	char *output;   // output redirection
	char *error;    // error redirection
	char *here_doc; // here document
}				t_redir;

// struct to store the command information
typedef struct cmd
{
	char *name;  // command name
	char **args; // arguments
	char *path;  // path to the command

	struct cmd *next; // next command
	struct cmd *prev; // previous command

	t_redir **redirs; // redirections

}				t_cmd;

// struct to store the file descriptors
typedef struct fds
{
	int fd_in;       // file descriptor for the input
	int fd_out;      // file descriptor for the output
	int fd_err;      // file descriptor for the error
	int fd_here_doc; // file descriptor for the here document
}				t_fds;

// struct to store the environment variable and its value
typedef struct env_var
{
	char *key;   // environment variable
	char *value; // value of the environment variable

	struct env_var *next; // next environment variable
	struct env_var *prev; // previous environment variable
}				t_env_var;

// struct to store the environment variables
typedef struct env
{
	t_env_var *head; // head of the environment variables
	t_env_var *last; // last of the environment variables
}				t_env;

// struct to store the shell information
typedef struct shell
{
	t_here_doc	*hd;

	t_env *env;         // environment variables
	char *line;         // line read from the input
	char *history_file; // file to store the history

	int ret;    // return value
	int status; // status of the shell

	t_fds *fds;   // file descriptors
	t_cmd **cmds; // commands
}				t_shell;

// main.c
// starter function to run the minishell program
int				main(int argc, char **argv, char **env);
// main function to run the minishell program

// shell.c
// main function to run the minishell program
void	run_shell(t_shell *shell); // function to run the shell

// init.c
// initializes the shell struct
t_shell	*init_shell(char **env); // function to initialize the shell

// utils.c
// prints the prompt
void			new_prompt(void);
// function to print a new prompt (newline) specially for Ctrl+C

// parse.c

// execute.c

// signals.c
void			setup_signals(void);
// function to setup the signals
void			siginfo_handler(int sig, siginfo_t *info, void *context);
// function to handle the SIGINFO signal

// builtins.c
void	exit_shell(t_shell *shell); // function to exit the shell

// env.c
void			assign_env_var(t_env_var *env_var, char *env);
// function to assign the key and value to the environment variable
void			add_env_var(t_env **env);
// function to add an env variable to the list
t_env			*copy_env(char **env);
// function to create a copy of the environment

// path.c

// here_doc.c

// history.c

// free.c
void	free_array(char **array); // function to free an array
void			close_fds(t_fds *fds);
// function to close the file descriptors
void	free_cmd(t_cmd *cmd);             // function to free a command
void	free_redir(t_redir *redirs);      // function to free a redirection
void	free_redirs(t_redir **redirs);    // function to free the redirections
void	free_cmd(t_cmd *cmd);             // function to free a command
void	free_cmds(t_cmd **cmds);          // function to free the commands
void	free_env_var(t_env_var *env_var);
		// function to free an environment variable
void	free_env(t_env *env);             // function to free the environment
void	free_shell(t_shell *shell);       // function to free the shell
void	clean_exit(t_shell *shell);       // function to exit the shell

// debug.c
void    print_env(t_env *env); // function to print the environment


// exit.c
void	exit_shell(t_shell *shell); // function to exit the shell

#endif
