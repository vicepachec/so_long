/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:39:10 by vpacheco          #+#    #+#             */
/*   Updated: 2021/06/30 12:48:53 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_treat_percent(t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_putstrprec("%", 1);
	char_count += ft_treat_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		char_count += ft_putstrprec("%", 1);
	return (char_count);
}
