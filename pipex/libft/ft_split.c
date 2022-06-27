/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:48:47 by amalbrei          #+#    #+#             */
/*   Updated: 2022/02/16 23:05:07 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	assigns(const char *s, char **str, char c, int count)
{
	int	j;
	int	i;
	int	start_index;

	i = 0;
	j = 0;
	while (i < count && s[j])
	{
		if (s[j] == c)
			j++;
		else
		{
			start_index = j;
			while (s[j] != c && s[j] != '\0')
				j++;
			str[i] = ft_substr(s, start_index, j - start_index);
			i++;
		}
	}
	str[i] = 0;
}

int	getwordcount(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
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

char	**ft_split(const char *s, char c)
{
	int		count;
	char	**str;

	if (!s)
		return (NULL);
	count = getwordcount(s, c);
	str = (char **)malloc((count + 1) * sizeof(char *));
	if (str == NULL)
		return (str);
	assigns(s, str, c, count);
	return (str);
}
