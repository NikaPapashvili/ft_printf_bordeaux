/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npapashv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:22:42 by npapashv          #+#    #+#             */
/*   Updated: 2024/10/23 21:46:54 by npapashv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf.h"

int	ft_manage_x(unsigned int n, char c)
{
	int		count;
	
	count = 0;
	if (c == 'X')
		count += ft_putnbr_uns_base(n, "0123456789ABCDEF", 16);
	else
		count += ft_putnbr_uns_base(n, "0123456789abcdef", 16);
	return (count);	
}
