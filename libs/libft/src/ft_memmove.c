/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:16:34 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/14 19:44:00 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest2;
	const unsigned char	*src2;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest2 == src2)
		return (dest);
	if (dest2 > src2)
		while (n-- > 0)
			dest2[n] = src2[n];
	else if (dest2 < src2)
	{
		while (i < n)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	return (dest);
}
/*int	main(void)
{
	char	dest3[] = "como estas";
	char	src3[] = "hello world";

	ft_memmove(dest3, src3, 15);
	printf("%s\n", dest3);
}*/
