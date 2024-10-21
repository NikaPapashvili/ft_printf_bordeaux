#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>

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

int ft_printf(const char *str, ...);

int	ft_format(const char *str, int f_index, va_list args, t_format *format);
int ft_skip_format(const char *str, int f_index);
int	ft_check_format(const char *str, int f_index);

// flags
t_format	*ft_format_new(const char *str, int f_index);
int			ft_isflag(const char c);

// Conversion management 
int	ft_manage_c(const char c, t_format *format);
int	ft_manage_s(const char *str, t_format *format);
int	ft_manage_p(void *ptr, t_format *format);
int	ft_manage_di(int n, t_format *format);
int	ft_manage_u(unsigned int n, t_format *format);
int	ft_manage_x(int	n, t_format *format, const char c);

// utils
int	ft_isdigit(const char c);
int	ft_occ_c(const char *str, char c);
int	ft_atoi(const char *str);
int	ft_strlen(const char *str);

// Outputs
int	ft_putnchar(const char c, int n);
int	ft_putnstr(const char *str, int n);
int	ft_putnbr_uns_base(unsigned long n, const char *base, int base_len);

#endif
