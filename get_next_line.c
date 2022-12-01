/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/25 13:59:34 by raanghel      #+#    #+#                 */
/*   Updated: 2022/12/01 17:43:38 by raanghel      ########   odam.nl         */
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

//delete later
char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (s && s[i])
	{
		dup[i] = s[i];
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

	i = 0;
	len = ft_strlen(reserve);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
		
	while (reserve[i] && reserve[i] != '\n')
	{
		dup[i] = reserve[i];
		i++;
	}
	dup[i] = '\n';
	// dup[i] = '\0';
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

size_t	nl_index(char *str)
{
	int i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len_s3;
	char	*s3;

	i = 0;
	j = 0;
	len_s3 = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc((len_s3 + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		s3[i] = s2[j];
		j++;
		i++;
	}
	s3[i] = '\0';
	return (s3);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	int				i;
	unsigned int	len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (len_s <= start)
		len = 0;
	else if (len_s - start < len)
		len = len_s - start;
	sub_str = (char *) malloc ((len + 1) * sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	while (len > 0 && start < len_s)
	{
		sub_str[i] = s[start];
		i++;
		start++;
		len--;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

static void	nl_found_in_reserve(char **reserve, char **line)
{
	size_t len_reserve;
	size_t len_line;
	char 	*reserve_temp;
	
	*line = ft_strdup_before_nl(*reserve);
	len_line = ft_strlen(*line);
	len_reserve = ft_strlen(*reserve);
	reserve_temp = ft_substr(*reserve, nl_index(*reserve), len_reserve - len_line);
	//reserve_temp = ft_strdup(ft_strchr(*reserve, '\n'));
	free(*reserve);
	*reserve = reserve_temp;
}



char *get_next_line(int fd)
{
	int				bytes_read;
	static char		*reserve;
	char			*line;
	char			buffer[BUFFER_SIZE + 1];
	
	line = NULL;
	fd = open("./text.txt", O_RDONLY);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0) // error
			return (NULL);
		buffer[bytes_read] = '\0';
		reserve = ft_strjoin(reserve, buffer);
		printf("reserve: %s\n", reserve);
		if (ft_strchr(reserve, '\n') != 0)
			break;
	}
	nl_found_in_reserve(&reserve, &line);
	// if (!line)
	// 	free (line);
	//printf("%s\n", line);
	return (line);
}

int	main(void)
{
	int	fd;
	
	fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
	//printf("line 1: %s")
	//get_next_line(fd);
	//system("leaks a.out");
}


// if (reserve == NULL)
// 	{
// 		reserve = malloc(1);
// 		if (reserve == NULL)
// 			return (NULL);
// 		reserve[0] = '\0';
// 	}

//printf("%s\n", str);
	// while (str)
	// {
	// 	printf("%s\n", str);
	// 	//free(str);
	// 	//get_next_line(fd);
	// }

// 	int	main(void)
// {
// 	int		fd;
// 	char	array[BUFFER_SIZE + 1];
// 	//char	*str;
// 	array[BUFFER_SIZE] = '\0';
// 	fd = open("./text.txt", O_RDONLY);
// 	//str = get_next_line(fd);
	
// 	int i = 1;
// 	ssize_t br;
// 	while ((br = read(fd, array, BUFFER_SIZE)) > 0)
// 	{
// 		for (int i = 0; i < br; i++)
// 			if (array[i] == '\n')
// 				array[i] = '$';
// 		array[br] = '\0';
// 		printf("call %d|%s|\n", i, array);
// 		i++;
// 	}
// }


// int	main(void)
// {
// 	int		fd;
// 	char	array[BUFFER_SIZE + 1];
// 	array[BUFFER_SIZE] = '\0';
// 	int call;
// 	int line;
	
// 	fd = open("./text.txt", O_RDONLY);
// 	line = read(fd, array, BUFFER_SIZE);
// 	call = 1;
// 	while (line > 0)
// 	{
// 		int	i = 0;
// 		while (i < line)
// 		{
// 			if (array[i] == '\n')
// 				array[i] = '$';
// 			i++;
// 		}
// 		array[line] = '\0';
// 		printf("Call: %d |%s|\n", call, array);
// 		call++;
// 		line = read(fd, array, BUFFER_SIZE);
// 	}
	
// 	//printf("Bytes read: %d\n", line);
// 	//printf("Stuff read: %s\n", array);
	
// }