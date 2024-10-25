/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npapashv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 04:17:18 by npapashv          #+#    #+#             */
/*   Updated: 2024/10/23 04:30:18 by npapashv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf.h"

int	ft_manage_p(void *ptr)
{
	unsigned long	adr;
	int				count;

	count = 0;
	adr = (unsigned long)ptr;
	if (ptr == NULL)
		count += ft_putnstr("(nil)", 5);
	else
	{
		count +=ft_putnstr("0x", 2);
		count += ft_putnbr_uns_base(adr, "0123456789abcdef", 16);
	}
	return (count);
}
