/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 23:04:45 by nuno              #+#    #+#             */
/*   Updated: 2025/01/13 20:37:10 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void cd_shell(t_cmd *cmd, t_env *env)
{
	char		*path;
	char		cwd[PATH_MAX];
	t_env_var	*oldpwd;
	t_env_var	*pwd;

	path = NULL;
	if (!cmd->args[1]) // No argument: go to $HOME
	{
		t_env_var *home = find_env_var(env, "HOME");
		if (!home || !home->value)
		{
			ft_putstr_fd("cd: HOME not set\n", STDERR_FILENO);
			return;
		}
		path = home->value;
	}
	else
		path = cmd->args[1];

	if (chdir(path) == -1)
		perror("cd error");
	else
	{
		if (getcwd(cwd, sizeof(cwd)))
		{
		// Update PWD and OLDPWD environment variables
		oldpwd = find_env_var(env, "OLDPWD");
		pwd = find_env_var(env, "PWD");
		if (oldpwd)
			free(oldpwd->value), oldpwd->value = ft_strdup(pwd ? pwd->value : "");
		if (pwd)
			free(pwd->value), pwd->value = ft_strdup(cwd);
		}
	}
}

