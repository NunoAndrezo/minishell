/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:09:42 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/17 18:11:21 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void run_shell(t_shell *shell)
{
    //for now it just starts the shell
    while (1)
    {
        //display the prompt
        ft_putstr_fd(PROMPT, 1);
        //read the input
        shell->line = readline();
        //print the input
        ft_putstr_fd(shell->line, 1);
    }
    //display the prompt
    //
    //read the input
    //
    //print the input
}
