/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:25:16 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/12 18:00:57 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*new_mem;
	size_t	i;

	len = ft_strlen(s);
	new_mem = (char *)malloc(len + 1);
	if (!new_mem)
		return (NULL);
	new_mem[len] = '\0';
	i = 0;
	while (i < len)
	{
		new_mem[i] = f(i, s[i]);
		i++;
	}
	return (new_mem);
}

/*int	main(void)
{
	char p[] = "hola";
	printf("cambio: %s", ft_strmapi(p, first_toupper));
}*/
