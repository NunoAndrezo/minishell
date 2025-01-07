/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:24:35 by joamiran          #+#    #+#             */
/*   Updated: 2024/12/30 16:28:15 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

// Check if the command is empty
bool is_empty(char *command)
{
    if (command[0] == '\0')
        return (true);
    return (false);
}

// Check if the command is a built-in command
bool is_builtin(char *command)
{
    if (ft_strcmp(command, "echo") == 0)
        return (true);
    if (ft_strcmp(command, "cd") == 0)
        return (true);
    if (ft_strcmp(command, "pwd") == 0)
        return (true);
    if (ft_strcmp(command, "export") == 0)
        return (true);
    if (ft_strcmp(command, "unset") == 0)
        return (true);
    if (ft_strcmp(command, "env") == 0)
        return (true);
    if (ft_strcmp(command, "exit") == 0)
        return (true);
    return (false);
}


// Check if the command is valid
bool validate_command(char *command)
{
    if (is_empty(command))
        return (false);
    if (!is_builtin(command))
        return (false);
    return (true);
}
