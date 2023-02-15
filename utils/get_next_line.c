/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:26:57 by vpacheco          #+#    #+#             */
/*   Updated: 2023/01/11 15:06:36 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	cloud[BUFFER_SIZE + 1];
	int			byte_read;

	line = NULL;
	byte_read = 1;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	while (byte_read)
	{
		if (!cloud[0])
			byte_read = read(fd, cloud, BUFFER_SIZE);
		if (byte_read > 0)
			line = joinstr(line, cloud);
		if (nl_check(cloud) || byte_read < 1)
			break ;
	}
	return (line);
}
