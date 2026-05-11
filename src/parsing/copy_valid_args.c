/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_valid_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 22:05:33 by joamiran          #+#    #+#             */
/*   Updated: 2025/06/02 22:18:18 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

// static int	copy_arg_and_strip(char **newargs, char **args, int *i, int *j)
// {
// 	char	*stripped;

// 	stripped = strip_quotes(args[*i]);
// 	if (!stripped)
// 	{
// 		while (*j > 0)
// 			free(newargs[--(*j)]);
// 		free(newargs);
// 		return (0);
// 	}
// 	newargs[(*j)++] = stripped;
// 	(*i)++;
// 	return (1);
// }

// char	**copy_valid_args(char **args, int count)
// {
// 	char	**newargs;
// 	int		i;
// 	int		j;
// 	int		ret;

// 	i = 0;
// 	j = 0;
// 	newargs = ft_calloc(sizeof(char *), count + 1);
// 	if (!newargs)
// 		return (NULL);
// 	while (args[i] && args[i][0] != '\0')
// 	{
// 		ret = handle_redir_copy(args, &i);
// 		if (ret == 0)
// 			break ;
// 		if (ret == -1 && !copy_arg_and_strip(newargs, args, &i, &j))
// 			return (NULL);
// 	}
// 	return (newargs);
// }

static int	copy_arg_and_strip(char **newargs, char **args, int *i, int *j)
{
	char	*stripped;

	stripped = strip_quotes(args[*i]);
	if (!stripped)
	{
		while (*j > 0)
			free(newargs[--(*j)]);
		free(newargs);
		return (0);
	}
	newargs[(*j)++] = stripped;
	(*i)++;
	return (1);
}

char	**copy_valid_args(char **args, int count)
{
	int		i;
	int		j;
	int		ret;
	char	**newargs;

	i = 0;
	j = 0;
	newargs = ft_calloc(sizeof(char *), count + 1);
	if (!newargs)
		return (NULL);
	while (args[i] && args[i][0] != '\0')
	{
		ret = handle_redir_copy(args, &i);
		if (ret == 0)
			break ;
		if (ret == -1 && !copy_arg_and_strip(newargs, args, &i, &j))
			return (NULL);
	}
	return (newargs);
}
