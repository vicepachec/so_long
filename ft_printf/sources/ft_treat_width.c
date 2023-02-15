/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:39:36 by vpacheco          #+#    #+#             */
/*   Updated: 2021/06/30 12:52:13 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_treat_width(int width, int minus, int has_zero)
{
	int	char_count;

	char_count = 0;
	while (width - minus > 0)
	{
		if (has_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		char_count++;
	}
	return (char_count);
}

int	ft_treat_width_int(int width, int minus, int has_zero, int neg_width)
{
	int	char_count;

	char_count = 0;
	while (width - minus > 0)
	{
		if (has_zero && !neg_width)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		char_count++;
	}
	return (char_count);
}
