/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npapashv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 03:11:14 by npapashv          #+#    #+#             */
/*   Updated: 2024/10/24 04:23:08 by npapashv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/ft_printf_bonus.h"

static void	ft_iter(const char *str, int *len_outputs, \
					va_list args, int *is_error)
{
	int			i;
	t_format	*format;

	i = 0;
	while (str[i])
	{
		if (!ft_check_format(str, i))
		{
			*len_outputs += ft_putnchar(str[i], 1);
			if (str[i] == '%')
				*is_error = -1;
			++i;
			continue ;
		}
		format = ft_format_new(str, i);
		if (format)
		{
			*len_outputs += ft_format(str, i, args, format);
			free(format);
		}
		if (*len_outputs == -1)
			*is_error = 1;
		i = ft_skip_format(str, i);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			len_outputs;
	int			is_error;

	if (str == NULL)
		return (-1);
	va_start(args, str);
	is_error = 0;
	len_outputs = 0;
	ft_iter(str, &len_outputs, args, &is_error);
	if (is_error)
		return (-1);
	return (len_outputs);
}
/*
#include <stdio.h>
int main(int ac, char const **av)
{
	int res_real;
	int res_fake;

	(void)ac;
	//(void)res_real;
	res_fake = ft_printf(av[1], av[2]);
	printf("\n");
	res_real = printf(av[1], av[2]);
	printf("\nres_fake: %d", res_fake);
	printf("\nres_real: %d\n", res_real);
	return 0;
}*/
