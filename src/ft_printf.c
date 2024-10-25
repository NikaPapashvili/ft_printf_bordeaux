/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npapashv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 03:11:14 by npapashv          #+#    #+#             */
/*   Updated: 2024/10/23 21:50:29 by npapashv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(const char *str, int i)
{
	int	res;

	if (str[i] != '%')
		return (0);
	res = 0;
	res = ft_occ_c("cspdiuxX%", str[i + 1]);
	return (res);
}

static void	ft_iter(const char *str, int *len_outputs, \
					va_list args, int *is_error)
{
	int			i;
	int			format_res;

	i = 0;
	while (str[i])
	{
		if (!ft_check_format(str, i))
		{
			*len_outputs += ft_putnchar(str[i], 1);
			++i;
			continue ;
		}
		format_res = ft_format(str, i, args);
		if (format_res == -1)
			*is_error = 1;
		else
			*len_outputs += format_res;
		if (str[i + 1])
			i += 2;
		else
			++i;
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
int main(int ac, const char **av)
{
	int res_real;
	int res_fake;

	(void)ac;
	//(void)res_real;
	res_fake = ft_printf(av[1], atoi(av[2]));
	printf("\n");
	res_real = printf(av[1], atoi(av[2]));
	printf("\nres_fake: %d", res_fake);
	printf("\nres_real: %d\n", res_real);
	return 0;
}*/
