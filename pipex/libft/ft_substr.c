/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:27:07 by amalbrei          #+#    #+#             */
/*   Updated: 2022/02/16 21:25:06 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*t;
	size_t			i;
	size_t			j;

	i = start;
	j = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	t = (char *)malloc(sizeof(char) * (len + 1));
	if (!t)
		return (0);
	while (i < ft_strlen(s) && j < len)
		t[j++] = s[i++];
	t[j] = '\0';
	return (t);
}
