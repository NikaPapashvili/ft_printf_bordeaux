/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npapashv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 03:10:35 by npapashv          #+#    #+#             */
/*   Updated: 2024/10/23 21:35:37 by npapashv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char *str, int f_index, va_list args)
{
	int	count;
	int	i;

	if (str == NULL || args == NULL)
		return (0);
	if (str[f_index] != '%')
		return (ft_putnchar(str[f_index], 1));
	count = 0;
	i = f_index + 1;
	if (str[i] == 'c')
		count += ft_manage_c(va_arg(args, int));
	else if (str[i] == 's')
		count += ft_manage_s(va_arg(args, char *));
	else if (str[i] == 'p')
		count += ft_manage_p(va_arg(args, void *));
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_manage_di(va_arg(args, int));
	else if (str[i] == 'u')
		count += ft_manage_u(va_arg(args, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		count += ft_manage_x(va_arg(args, unsigned int), str[i]);
	else if (str[i] == '%')
		count += ft_putnchar('%', 1);
	return (count);
}
