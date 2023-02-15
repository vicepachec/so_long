/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:20:44 by vpacheco          #+#    #+#             */
/*   Updated: 2023/02/15 16:04:55 by vpacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int	get_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = get_len(n);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (n < 0)
		result[0] = '-';
	else if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		--len;
		result[len] = absolute_value(n % 10) + '0';
		n = n / 10;
	}
	return (result);
}

void	coord(int x, int y, t_data *data)
{
	data->player_x = x * 64;
	data->player_y = y * 64;
}

int	check_valid(t_data *data, char *str, int counter)
{	
	int	i;

	i = -1;
	while (str[++i] != '\n' && str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] \
			!= 'E' && str[i] != 'P' && str[i] != 'X')
			print_error(1, "Caracter Invalida", data);
		if (str[i] == 'P')
		{
			data->player_count++;
			coord(i, counter, data);
		}
		if (str[i] == 'E')
			data->exit_count++;
		if (str[i] == 'C')
			data->col++;
	}
	return (0);
}
