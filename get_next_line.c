/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 13:59:34 by raanghel      #+#    #+#                 */
/*   Updated: 2022/11/25 18:09:20 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include <fcntl.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
#endif

// char	*get_next_line(int fd)
// {
	
// }
#include<stdio.h>

int	main(void)
{
	int		fd;
	char	array[BUFFER_SIZE + 1];
	//char	*str;
	array[BUFFER_SIZE] = '\0';
	fd = open("./text.txt", O_RDONLY);
	//str = get_next_line(fd);
	
	int i = 1;
	ssize_t br;
	while ((br = read(fd, array, BUFFER_SIZE)) > 0)
	{
		for (int i = 0; i < br; i++)
			if (array[i] == '\n')
				array[i] = '$';
		array[br] = '\0';
		printf("call %d|%s|\n", i, array);
		i++;
	}
	//printf("%s\n", str);
	// while (str)
	// {
	// 	printf("%s\n", str);
	// 	//free(str);
	// 	//get_next_line(fd);
	// }
}
