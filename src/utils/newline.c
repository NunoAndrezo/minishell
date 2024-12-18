/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:51:30 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/18 21:13:43 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Function to print a new prompt (newline) specially for Ctrl+C
void	new_prompt(void)
{
    ft_printf("\n");
    rl_on_new_line();
    rl_replace_line("", 14);
    rl_redisplay();
}
