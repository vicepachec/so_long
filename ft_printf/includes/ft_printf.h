/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:38:18 by vpacheco          #+#    #+#             */
/*   Updated: 2021/06/30 13:58:31 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int				already_print;
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
	int				neg_width;
}					t_flags;

int					ft_printf(const char *str, ...);
int					ft_is_in_type_list(int c);
int					ft_is_in_flags_list(int c);
int					ft_treatment(int c, t_flags flags, va_list args);
int					ft_treat_width(int width, int minus, int has_zero);
int					ft_treat_width_int(int width, int minus, int has_zero,
						int neg_widt);
int					ft_putstrprec(char *str, int prec);
int					ft_treat_char(char c, t_flags flags);
int					ft_treat_string(char *str, t_flags flags);
int					ft_treat_int(int i, t_flags flags, int char_count,
						int save_i);
int					ft_treat_percent(t_flags flags);
int					ft_treat_hexa(unsigned int ui, int lower, t_flags flags);
int					ft_treat_uint(unsigned int unsi, t_flags flags);
int					ft_flag_dot(const char *save, int start,
						t_flags *flags, va_list args);
int					ft_putchar(int c);
int					ft_treat_pointer(unsigned long long pointer, t_flags flags);

char				*ft_ull_base(unsigned long long ull, int base);
char				*ft_u_itoa(unsigned int n);
char				*ft_str_tolower(char *str);

t_flags				ft_flag_minus(t_flags flags);
t_flags				ft_flag_width(va_list args, t_flags flags);
t_flags				ft_flag_digit(char c, t_flags flags);

#endif
