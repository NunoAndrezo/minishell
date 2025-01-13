/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls??.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 02:12:10 by nuno              #+#    #+#             */
/*   Updated: 2025/01/13 20:35:32 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ls_shell(t_cmd *cmd)
{
	pid_t pid;
	char *path;

	pid = fork();
	if (pid == 0) // Child process
	{
		path = "/bin/ls"; // Hardcoded path to `ls` binary
		if (execve(path, cmd->args, NULL) == -1)
		{
			perror("ls error"); // write(2, ..., )?
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
