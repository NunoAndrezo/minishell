/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:01:28 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/18 02:07:35 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../inc/lib_ft/libft.h"
# include "../inc/lib_ft/get_next_line.h"
# include "../inc/lib_ft/ft_printf.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>

# define PROMPT "minishell$ "
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

typedef struct here_doc
{
	char		*delim;
	char		*content;
	char		*file;

	int			fd;
}				t_here_doc;

typedef struct shell
{
	t_here_doc	*hd;

	char		**env;
	char		**path;
	char		*line;
	char		**args;
	char		*cmd;
	char		*history_file;

	int			ret;
	int			status;
	int			fd_in;
	int			fd_out;
	int			fd_err;
	int			fd_hd;
}				t_shell;

// main.c
// starter function to run the minishell program
int     main(void);

// shell.c
// main function to run the minishell program
void    run_shell(t_shell *shell);

// init.c
// initializes the shell struct
t_shell *init_shell(void);

// utils.c

// parse.c

// execute.c

// signals.c

// builtins.c

// env.c

// path.c

// here_doc.c

// history.c

#endif
