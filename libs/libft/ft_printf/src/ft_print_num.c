/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:27:29 by seizquie          #+#    #+#             */
/*   Updated: 2025/06/11 13:45:24 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_print_str("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += ft_print_char('-');
		n *= -1;
	}
	if (n >= 10)
		count += ft_print_num(n / 10);
	count += ft_print_char((n % 10) + '0');
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	count += ft_print_char((n % 10) + '0');
	return (count);
}
