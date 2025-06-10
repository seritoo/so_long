/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:34:54 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/11 18:06:59 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, (s++), 1);
}
/*int main()
{
	char p[] = "holartf";
	int fd = open("prueba", O_CREAT | O_WRONLY, 0777);
	ft_putstr_fd(p, fd);
}*/
