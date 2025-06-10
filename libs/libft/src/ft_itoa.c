/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:07:42 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/13 21:05:41 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	count_w(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_w(n);
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	new[len--] = '\0';
	if (n == 0)
		new[0] = '0';
	if (n < 0)
	{
		new[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		new[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (new);
}
