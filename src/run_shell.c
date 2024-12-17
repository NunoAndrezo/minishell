/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:09:42 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/17 21:33:38 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// This function initializes the shell
t_shell	*init_shell(void)
{
	t_shell	*shell;

	ft_printf("Initializing shell\n"); // print initializing shell
	shell = ft_calloc(1, sizeof(t_shell)); // allocate memory for the shell
	if (!shell)
	{
		ft_putstr_fd("Error: malloc failed\n", 2);
		exit(1);
	}
	
	ft_printf("Shell initialized\n");
	return (shell);
}

void	run_shell(t_shell *shell)
{
	// for now it just starts the shell
	while (1)
	{
		// read the input
		shell->line = readline(PROMPT);
		// print the input
		if (shell->line)
		{
            // if the input is "exit" then break the loop
			if (ft_strcmp(shell->line, "exit") == 0)
				break ;

            // print the input and the number of letters
			ft_printf("[%s] with [%d] letters\n", shell->line,
				ft_strlen(shell->line));

			// free the input
			free(shell->line);
		}
	}

    // print the exit message
	ft_printf("Exiting minishell\n");
	
    // free the shell
    free(shell->line);
	free(shell);
}
