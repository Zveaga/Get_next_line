/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/12 17:17:16 by raanghel      #+#    #+#                 */
/*   Updated: 2022/12/15 14:58:45 by raanghel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strchr(const char *str, int c)
{	
	if (str == NULL)
		return (0);
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
