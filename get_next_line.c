/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 13:59:34 by raanghel      #+#    #+#                 */
/*   Updated: 2023/11/22 13:25:15 by coxer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_reserve(char *reserve)
{
	char	*dup;
	int		i;
	int		j;

	i = len_line(reserve);
	if (reserve[i] == '\0')
	{
		free(reserve);
		return (NULL);
	}
	dup = malloc(sizeof(char) * (ft_strlen(reserve) - i + 1));
	if (dup == NULL)
	{
		free(reserve);
		reserve = NULL;
		return (NULL);
	}
	j = 0;
	while (reserve[i])
	{
		dup[j] = reserve[i];
		j++;
		i++;
	}
	dup[j] = '\0';
	free(reserve);
	return (dup);
}

static char	*save_line(char *reserve)
{
	int		i;
	char	*dup;
	int		flag;

	i = len_line(reserve);
	dup = malloc(sizeof(char) * (i + 1));
	i = 0;
	flag = 0;
	if (dup == NULL)
		return (NULL);
	while (reserve && reserve[i] && (flag == 0))
	{
		dup[i] = reserve[i];
		if (reserve[i] == '\n')
			flag = 1;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*reserve;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	reserve = malloc((len + 1) * sizeof(char));
	if (reserve == NULL)
	{
		free(s1);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		reserve[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		reserve[i++] = s2[j++];
	free(s1);
	reserve[i] = '\0';
	return (reserve);
}

static char	*read_and_reserve(char *reserve, int fd)
{	
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		free(reserve);
		return (NULL);
	}
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(reserve);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		reserve = ft_strjoin(reserve, buffer);
		if (reserve == NULL || ft_strchr(reserve, '\n') != 0)
			break ;
	}
	free(buffer);
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char		*reserve;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reserve = read_and_reserve(reserve, fd);
	if (reserve == NULL)
		return (NULL);
	line = save_line(reserve);
	if (line == NULL)
	{
		if (reserve)
		{
			free(reserve);
			reserve = NULL;
		}
		return (NULL);
	}
	reserve = update_reserve(reserve);
	return (line);
}

