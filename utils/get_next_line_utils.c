/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:27:36 by vpacheco          #+#    #+#             */
/*   Updated: 2023/01/11 15:06:51 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

static size_t	lencount(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	return (i + (str[i] == '\n'));
}

char	*joinstr(char *line, char *cloud)
{
	size_t	cloud_size;
	size_t	i;
	size_t	j;
	char	*str;

	cloud_size = lencount(cloud);
	str = malloc(sizeof(char) * (lencount(line) + cloud_size + 1));
	if (!str)
		return (NULL);
	j = -1 * (line != NULL);
	while (line && line[++j])
		str[j] = line[j];
	i = 0;
	while (i < cloud_size)
		str[j++] = cloud[i++];
	str[j] = 0;
	if (line)
		free(line);
	return (str);
}

char	nl_check(char *cloud)
{
	char	is_nl;
	int		j;
	int		i;

	j = 0;
	i = 0;
	is_nl = 0;
	while (cloud[i])
	{
		if (is_nl)
			cloud[j++] = cloud[i];
		if (cloud[i] == '\n')
			is_nl = 1;
		cloud[i] = 0;
		i++;
	}
	return (is_nl);
}
