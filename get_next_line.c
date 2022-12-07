/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 13:59:34 by raanghel      #+#    #+#                 */
/*   Updated: 2022/12/07 16:51:52 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

static	int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup_after_nl(const char *reserve)
{
	char	*dup;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(reserve);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (reserve && reserve[i])
	{
		dup[i] = reserve[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup_before_nl(const char *reserve)
{
	char	*dup;
	int		len;
	int		i;
	int		flag;

	i = 0;
	len = 0;
	while (reserve && reserve[len] != '\n' && reserve[len])	
		len++;
	if (reserve && reserve[len] == '\n')
		len++;
	dup = malloc(sizeof(char) * (len + 1));
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

char	*ft_strchr(const char *str, int c)
{	
	while (str && *str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (0);
}

char	*ft_strchr_no_nl(const char *str, int c)
{	
	while (str && *str)
	{
		if (*str == (char)c)
			return ((char *)str + 1);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (0);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len_s3;
	char	*reserve;

	i = 0;
	j = 0;
	len_s3 = ft_strlen(s1) + ft_strlen(s2);
	reserve = malloc((len_s3 + 1) * sizeof(char));
	if (reserve == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		reserve[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		reserve[i] = s2[j];
		j++;
		i++;
	}
	reserve[i] = '\0';
	return (reserve);
}

static void	nl_found_in_reserve(char **reserve, char **line)
{
	char	*reserve_temp;

	*line = ft_strdup_before_nl(*reserve);
	if (*line == NULL)
	{
		free(*line);
		free(*reserve);
		*line = NULL;
		*reserve = NULL;
	}
	reserve_temp = ft_strdup_after_nl(ft_strchr_no_nl(*reserve, '\n'));
	free(*reserve);
	*reserve = reserve_temp;
}

char *read_line(int bytes_read, char **reserve, char *buffer, int fd)
{	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{	
			free(buffer);
			return (NULL);
		}
		else if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		*reserve = ft_strjoin(*reserve, buffer);
		if (ft_strchr(*reserve, '\n') != 0)
			break;
	}
	free(buffer);
	return (*reserve);
}

char *get_next_line(int fd)

{
	int				bytes_read;
	static char		*reserve;
	char			*line;
	char			*buffer;
	
	line = NULL;
	buffer = NULL;
	bytes_read = 0;
	read_line(bytes_read, &reserve, buffer, fd);
	nl_found_in_reserve(&reserve, &line);
	if (ft_strlen(line) == 0)
		line = NULL;
	if (!line)
	{
		free(line);
		free(reserve);
		free(buffer);
		line = NULL;
		reserve = NULL;
		buffer = NULL;
	}
	//printf("%s", line);
	free(buffer);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	fd = open("text.txt", O_RDONLY);
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	get_next_line(fd);
// 	//get_next_line(fd);
// }

int main(void)
{
	int		fd;
	char	*line;
	
	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}

// if (reserve == NULL)
// 	{
// 		reserve = malloc(1);
// 		if (reserve == NULL)
// 			return (NULL);
// 		reserve[0] = '\0';
// 	}


// char *get_next_line(int fd)
// {
// 	int				bytes_read;
// 	static char		*reserve;
// 	char			*line;
// 	char			buffer[BUFFER_SIZE + 1];
	
// 	line = NULL;
// 	bytes_read = 1;
// 	while (bytes_read > 0)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read < 0)
// 			return (NULL);
// 		buffer[bytes_read] = '\0';
// 		reserve = ft_strjoin(reserve, buffer);
// 		printf("%s\n", reserve);
// 		if (ft_strchr(reserve, '\n') != 0 || bytes_read < BUFFER_SIZE)
// 			break;
// 	}
// 	nl_found_in_reserve(&reserve, &line);
// 	// if (!line)
// 	// 	free (line);
// 	// printf("%s", line);
// 	return (line);
// }

// char	*ft_strdup_before_nl_orig(const char *reserve)
// {
// 	char	*dup;
// 	int		len;
// 	int		i;

// 	i = 0;
// 	len = ft_strlen(reserve);
// 	dup = malloc(sizeof(char) * (len + 1));
// 	if (dup == NULL)
// 		return (NULL);
// 	while (reserve[i] && reserve[i] != '\n')
// 	{
// 		dup[i] = reserve[i];
// 		i++;
// 	}
// 	dup[i] = '\n';
// 	//dup[i] = '\0';
// 	return (dup);
// }


// char	*reserve_temp;

// 	*line = ft_strdup_before_nl(*reserve);
// 	reserve_temp = ft_strdup_after_nl(ft_strchr(*reserve, '\n'));
// 		if (*reserve_temp == '\n')
// 			reserve_temp++;
// 	free(*reserve);
// 	*reserve = reserve_temp;