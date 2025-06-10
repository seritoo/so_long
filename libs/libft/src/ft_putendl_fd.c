/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:01:28 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/11 19:15:32 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/libft.h"
#include <fcntl.h>
#include <sys/stat.h>

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, (s++), 1);
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	char p[] = "holartf";
// 	int fd = open("prueba", O_CREAT | O_WRONLY, 0777);
// 	ft_putendl_fd(p, fd);
// }
