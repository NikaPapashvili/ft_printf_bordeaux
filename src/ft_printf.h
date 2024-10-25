/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npapashv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 03:11:27 by npapashv          #+#    #+#             */
/*   Updated: 2024/10/23 21:19:04 by npapashv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct s_format
{
	int	blank;
	int	dash;
	int	zero;
	int	plus;
	int	hash;
	int	dot;
	int	precision;
	int	width;
}	t_format;

int			ft_printf(const char *str, ...);
int			ft_format(const char *str, int i, va_list args);			

// Conversion management 
int			ft_manage_c(const char c);
int			ft_manage_s(const char *str);
int			ft_manage_p(void *ptr);
int			ft_manage_di(int n);
int			ft_manage_u(unsigned int n);
int			ft_manage_x(unsigned int n, char c);

// utils
int			ft_isdigit(const char c);
int			ft_atoi(const char *str);
int			ft_occ_c(const char *str, const char c);
int			ft_strlen(const char *str);

// Outputs
int			ft_putnchar(const char c, int n);
int			ft_putnstr(const char *str, int n);
int			ft_putnbr_uns_base(unsigned long n, const char *base, int base_len);

#endif
