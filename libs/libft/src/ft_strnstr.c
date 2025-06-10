/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:31:44 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/13 19:55:08 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	little_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)(big));
	i = 0;
	while (i < len && big[i] != '\0')
	{
		if (len - i < little_len)
			return (NULL);
		if (ft_strncmp(&big[i], little, little_len) == 0)
			return ((char *)(&big[i]));
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char big2[] = "hola como estas";
	char little2[] = "como";

	printf("encontrado en: %s\n", ft_strnstr(big2, little2, 9));
}*/
