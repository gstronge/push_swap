/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:02:45 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/13 12:37:53 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	write(fd, s, count);
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	char	*s = "abcdefg";
// 	int		fd;

// 	fd = open("test.pdf", O_RDWR);

// 	ft_putstr_fd(s, fd);
// }