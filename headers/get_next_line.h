/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:13:16 by vpacheco          #+#    #+#             */
/*   Updated: 2023/01/11 18:33:50 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <unistd.h>
# include <stdlib.h>

char	*joinstr(char *line, char *cloud);
char	nl_check(char *cloud);
char	*get_next_line(int fd);

#endif
