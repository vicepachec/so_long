/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:38:41 by vpacheco          #+#    #+#             */
/*   Updated: 2021/06/30 12:28:28 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_str_tolower(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}
