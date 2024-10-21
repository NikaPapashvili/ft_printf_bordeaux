#include "ft_printf.h"


int	ft_format(const char *str, int f_index, va_list args, t_format *format)
{
	int	count;
	int	i;

	if (str == NULL || args == NULL || format == NULL)
		return (0);
	if (str[f_index] != '%')
		return (ft_putnchar(str[f_index], 1));
	count = 0;
	i = ft_skip_format(str, f_index) - 1;
	if (str[i] == 'c')
		count += ft_manage_c(va_arg(args, int), format);
	else if (str[i] == 's')
		count += ft_manage_s(va_arg(args, char *), format);
	else if (str[i] == 'p')
		count += ft_manage_p(va_arg(args, void *), format);
	else if (str[i] == 'd' || str[i] =='i')
		count += ft_manage_di(va_arg(args, int), format);
	else if (str[i] == 'u')
		count += ft_manage_u(va_arg(args, unsigned int), format);
	else if (str[i] == 'x' || str[i] == 'X')
		count += ft_manage_x(va_arg(args, int), format, str[i]);
	else if (str[i] == '%')
		count += ft_putnchar('%', 1);
	return (count);
}

int	ft_skip_format(const char *str, int f_index)
{
	int	i;
	int	is_conversion;

	i = f_index + 1;
	while (ft_isflag(str[i]))
		++i;
	while (ft_isdigit(str[i]))
		++i;
	if (str[i] == '.')
		++i;
	while (ft_isdigit(str[i]))
		++i;
	is_conversion = ft_occ_c("cspdiuxX%", str[i]);
	if (!is_conversion && str[i])
		return (f_index + 1);
	return (i + 1);
}

int	ft_check_format(const char *str, int f_index)
{
	int	i;
	int	is_conversion;

	if (str[f_index] != '%')
		return (0);
	i = ft_skip_format(str, f_index);
	if (i == f_index + 1)
	    return (0);
	is_conversion = ft_occ_c("cspdiuxX%", str[i - 1]);
	return (is_conversion);
}
