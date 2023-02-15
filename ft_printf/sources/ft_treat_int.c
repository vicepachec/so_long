/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:39:03 by vpacheco          #+#    #+#             */
/*   Updated: 2021/09/02 10:09:17 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_in_put_part_int(char *d_i, int save_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (save_i < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		char_count += ft_treat_width_int (flags.dot - 1, ft_strlen(d_i) - 1,
				1, (flags.neg_width && flags.zero));
	char_count += ft_putstrprec(d_i, ft_strlen(d_i));
	return (char_count);
}

static int	ft_put_part_int(char *d_i, int save_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_int(d_i, save_i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d_i))
		flags.dot = ft_strlen(d_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width_int(flags.width, 0, 0,
				(flags.neg_width && flags.zero));
	}
	else
		char_count += ft_treat_width_int(flags.width, ft_strlen(d_i),
				flags.zero, (flags.neg_width && flags.zero));
	if (flags.minus == 0)
		char_count += ft_in_put_part_int(d_i, save_i, flags);
	return (char_count);
}

int	ft_treat_int(int i, t_flags flags, int char_count, int save_i)
{
	char	*d_i;

	save_i = i;
	if (flags.dot == 0 && i == 0)
	{
		char_count += ft_treat_width_int(flags.width, 0, 0,
				(flags.neg_width && flags.zero));
		return (char_count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
			ft_putstrprec("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		char_count++;
	}
	if (i == -2147483648)
		d_i = ft_strdup("-2147483648");
	else
		d_i = ft_itoa(i);
	char_count += ft_put_part_int(d_i, save_i, flags);
	free(d_i);
	return (char_count);
}
