/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:00:36 by amalbrei          #+#    #+#             */
/*   Updated: 2022/07/04 16:52:38 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex_getwordcount(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i + 1] == '"')
		{
			i += 2;
			while (s[i] != '"')
				i++;
		}
		else if (s[i] == c)
			i++;
		else if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			j++;
			i++;
		}
		else if (s[i] != c && s[i + 1] != c)
			i++;
	}
	return (j);
}

void	pipex_assigns(const char *s, char **str, char c, int count)
{
	int	i;
	int	j;
	int	start_index;

	i = 0;
	j = 0;
	while (i < count && s[j])
	{
		while (s[j] == c)
			j++;
		if (s[j] == '"')
			j++;
		start_index = j;
		if (s[j - 1] == '"')
			while (s[j] != '"')
				j++;
		else
			while (s[j] != c && s[j] != '\0')
				j++;
		str[i] = ft_substr(s, start_index, j - start_index);
		i++;
	}
	str[i] = 0;
}

char	**pipex_split(const char *s, char c)
{
	char	**str;
	int		count;

	if (!s)
		return (NULL);
	count = pipex_getwordcount(s, c);
	str = (char **)malloc((count + 1) * sizeof(char *));
	if (str == NULL)
		return (str);
	pipex_assigns(s, str, c, count);
	return (str);
}
