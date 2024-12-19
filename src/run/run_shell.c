/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:09:42 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/19 20:27:43 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void execute(t_shell *shell)
{
}




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
            exit_shell(shell);
	
		if (shell->line)
		{
            parse(shell); // parse the line and tokens
            if (shell->tokens)
            {
                if (ft_strcmp(shell->tokens[0], "exit") == 0)
                    exit_shell(shell);
                if (ft_strcmp(shell->tokens[0], "env") == 0)
                    print_env(shell->env);
                if (ft_strcmp(shell->tokens[0], "unset") == 0)
                {
                    int i = 0;
                    while (shell->tokens[i])
                    {
                        unset_env_var(shell, shell->tokens[i]);
                        i++;
                    }
                }
                free_tokens(shell->tokens); // free the tokens
			    free(shell->line);
            }
        }
    }
}

