/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 13:38:48 by raanghel      #+#    #+#                 */
/*   Updated: 2022/12/12 17:24:24 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<fcntl.h>
# include<unistd.h>
# include<stdio.h> // -> REMOVE!!
# include<string.h> // -> REMOVE!!
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif

char	*get_next_line(int fd);

char	*ft_strchr(const char *str, int c);

int		ft_strlen(const char *s);

#endif