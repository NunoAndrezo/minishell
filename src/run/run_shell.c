/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:09:42 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/30 16:31:24 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_shell(t_shell *shell)
{
	// setup the signal handler
	setup_signals();
	// for now it just starts the shell
	while (1)
	{
		// read the input
		shell->line = readline(PROMPT);
		if (!shell->line)
			exit_shell(shell);
		if (shell->line)
		{
			parse(shell); // parse the line and tokens
			if (shell->tokens)
			{
                // check the validity of the command
               // if (validate_command(shell->tokens)
               // {
               //     // execute the command
               //     //execute_command(shell);
               // }
               // else
               // {
               //     // print an error message
               //     ft_putstr_fd("minishell: command not found: ", 2);
               //     ft_putstr_fd(shell->tokens->content, 2);
               //     ft_putstr_fd("\n", 2);
               // }
				free_tokens(shell->tokens); // free the tokens
				free(shell->line);
			}
		}
	}
}
