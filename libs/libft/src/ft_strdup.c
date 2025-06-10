/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:31:26 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/13 17:46:57 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dub;

	len = ft_strlen(s) + 1;
	dub = malloc(len);
	if (!dub)
		return (NULL);
	ft_strlcpy(dub, s, len);
	return (dub);
}

/*int	main(void)
{
	char uv[] = "hola";
	char *duplicado = ft_strdup(uv);

	printf("Cadena original: %s\n", uv);
	printf("Cadena duplicada: %s\n", duplicado);
}*/
