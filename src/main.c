/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:56:43 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/18 21:40:58 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int main(int argc, char **argv, char **env)
{
    (void)argv;

    // if it has any arguments, print the error message
    if (argc > 1)
    {
        ft_putstr_fd("Error: minishell does not accept arguments\n", 2);
        //print monke to error
        ft_putstr_fd(monke, 2);

        return (1);
    }

    t_shell *shell;
    
    shell = init_shell(env);

    run_shell(shell);
    return (0);
}

