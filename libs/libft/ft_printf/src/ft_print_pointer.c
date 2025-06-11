/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:27:29 by seizquie          #+#    #+#             */
/*   Updated: 2025/06/11 13:45:29 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *c)
{
	int		count;
	size_t	n;

	count = 0;
	if (c == 0)
		count += ft_print_str("(nil)");
	else
	{
		count += ft_print_str("0x");
		n = (size_t)c;
		count += ft_print_hexadecimal(n, 'x');
	}
	return (count);
}
