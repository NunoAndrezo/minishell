/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:09:42 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/18 22:24:26 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_shell(t_shell *shell)
{
    //setup the signal handler
    setup_signals();

	// for now it just starts the shell
	while (1)
	{
		// read the input
		shell->line = readline(PROMPT);

        if (!shell->line)
        {
            ft_printf("exiting\n");
            exit_shell(shell);
        }
	
        // print the input
		if (shell->line)
		{
            // if the input is "exit" then break the loop
			if (ft_strcmp(shell->line, "exit") == 0)
                exit_shell(shell);
            
            if (ft_strcmp(shell->line, "env") == 0)
                print_env(shell->env);
            // print the input and the number of letters
			ft_printf("line goes brrrrrr \n");

			// free the input
			free(shell->line);
		}
	}
}
