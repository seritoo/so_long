/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:55:51 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/13 17:53:00 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	lens;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	lens = src_len + dst_len;
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (lens);
}
/*
int main (void)
{
	char	dest[20] = "hola";
	char	src[] = "mundo";
	size_t	res;

	res = ft_strlcat(dest + 1, src, sizeof(dest));
	printf("resultado: %s\n", dest);
	printf("tamaño: %zu", res);
}*/
