/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 03:49:29 by marvin            #+#    #+#             */
/*   Updated: 2021/06/30 11:30:37 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char			*arra;
	size_t			i;
	unsigned int	total;

	total = nitems * size;
	arra = malloc(nitems * size);
	if (arra == NULL)
		return (NULL);
	i = 0;
	while (total > 0)
	{
		arra[i] = 0;
		total--;
		i++;
	}
	return ((void *)arra);
}
