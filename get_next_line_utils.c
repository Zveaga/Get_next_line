/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/12 17:17:16 by raanghel      #+#    #+#                 */
/*   Updated: 2022/12/19 21:36:32 by rares         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

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

int	ft_strlen(const char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	len_line(char *reserve)
{
	int	i;

	i = 0;
	while (reserve[i] != '\n' && reserve[i])
		i++;
	if (reserve[i] == '\n')
		i++;
	return (i);
}
