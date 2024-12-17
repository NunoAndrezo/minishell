/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:56:43 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/17 21:24:08 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int main()
{
    t_shell *shell;
    
    ft_printf("\U0001F600Welcome to minishell\U0001F600\n");

    shell = init_shell();

    run_shell(shell);
    return (0);
}

