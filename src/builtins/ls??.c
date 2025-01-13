/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls??.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 02:12:10 by nuno              #+#    #+#             */
/*   Updated: 2025/01/09 03:30:13 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ls_shell(t_cmd *cmd)
{
	pid_t pid;

	pid = fork();
	if (pid == 0) // Child process
	{
		char *path = "/bin/ls"; // Hardcoded path to `ls` binary
		if (execve(path, cmd->args, NULL) == -1)
		{
		perror("ls error");
		exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0) // Parent process
	{
		wait(NULL); // Wait for child to finish
	}
	else
	{
		perror("fork error");
	}
}
