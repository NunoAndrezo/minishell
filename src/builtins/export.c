/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:47:26 by nuno              #+#    #+#             */
/*   Updated: 2025/01/09 02:55:07 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void export_shell(t_cmd *cmd, t_env *env)
{
	int	i;
	char *key;
	char *value;
	t_env_var *var;

	i = -1;
	key = NULL;
	value = NULL;
	var = NULL;
	if (!cmd->args[1]) // No arguments: print all environment variables
	{
		t_env_var *var = env->head;
		while (var)
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(var->key, STDOUT_FILENO);
			if (var->value)
			{
				ft_putstr_fd("=\"", STDOUT_FILENO);
				ft_putstr_fd(var->value, STDOUT_FILENO);
				ft_putstr_fd("\"", STDOUT_FILENO);
			}
			ft_putchar_fd('\n', STDOUT_FILENO);
			var = var->next;
		}
		return;
	}
	while (cmd->args[++i]) // Add/modify variables
	{
		key = ft_substr(cmd->args[i], 0, ft_strchr(cmd->args[i], '=') - cmd->args[i]);
		value = ft_strdup(ft_strchr(cmd->args[i], '=') + 1);
		var = find_env_var(env, key);
		if (var)
		{
			free(var->value);
			var->value = value;
		}
		else
		{
			add_env_var(&env);
			assign_env_var(env->last, cmd->args[i]);
		}
		free(key);
	}
}

