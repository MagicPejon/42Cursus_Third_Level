/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:23:31 by amalbrei          #+#    #+#             */
/*   Updated: 2022/03/16 14:41:33 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*assign(char *str, int i, int n)
{
	long	l;

	l = n;
	if (n < 0)
	{
		str[0] = '-';
		l *= -1;
	}
	while (i > 0)
	{
		if (str[i - 1] == '-')
			break ;
		str[i - 1] = (l % 10) + '0';
		l /= 10;
		i--;
	}
	return (str);
}	

int	counter(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = counter(n);
	str = ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (str);
	str = assign(str, i, n);
	return (str);
}
