/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 22:03:38 by joamiran          #+#    #+#             */
/*   Updated: 2025/06/02 22:03:46 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

static int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

static void	handle_quote(char c, char *in_quote)
{
	if (*in_quote == 0)
		*in_quote = c;
	else if (*in_quote == c)
		*in_quote = 0;
}

char	*strip_quotes(const char *s)
{
	char	*result;
	int		i;
	int		j;
	char	in_quote;

	if (!s)
		return (NULL);
	result = malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	in_quote = 0;
	while (s[i])
	{
		if (is_quote(s[i]) && (!in_quote || s[i] == in_quote))
			handle_quote(s[i], &in_quote);
		else
			result[j++] = s[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}
