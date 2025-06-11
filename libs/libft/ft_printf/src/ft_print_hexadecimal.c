/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:27:29 by seizquie          #+#    #+#             */
/*   Updated: 2025/06/11 13:45:14 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexadecimal(size_t n, char c)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_print_hexadecimal((n / 16), c);
	count += ft_print_char(base[n % 16]);
	return (count);
}
