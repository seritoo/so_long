/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:34:56 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/13 17:51:28 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*p;

	len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, (ft_strlen(s1) + 1));
	printf("hola\n");
	ft_strlcat(p, s2, len + 1);
	free((char *)s1);
	return (p);
}
// int	main(void)
// {
// 	char const name[] = "Juan ";
// 	char const name2[] = "Andres";
// 	printf("cadena nueva: %s", ft_strjoin(name, name2));
// }
