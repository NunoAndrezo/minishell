/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao <joao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 02:15:08 by nuno              #+#    #+#             */
/*   Updated: 2025/06/01 17:52:14 by joao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_builtins.h"

// function to close all extra file descriptors
static void	close_extra_fds(void)
{
	int	i;

	i = 3;
	while (i < 1024)
	{
		close(i);
		i++;
	}
}

// function to clean up and exit the shell
void	exit_shell(t_cmd *cmd, t_shell *shell)
{
	(void)cmd;
	if (!shell->is_child)
		shell->exit_value = 0;
	close_extra_fds();
	clean_exit(&shell);
}
