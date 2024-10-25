#include "../src_bonus/ft_printf_bonus.h"

static int ft_justifyleft(t_format *format, const char *str);
static int ft_justifyright(t_format *format, const char *str);
static int ft_manage_null(t_format *format);

int	ft_manage_s(const char *str, t_format *format)
{
	int	count;

	if (format == NULL)
		return (0);
	count = 0;
	if (str == NULL)
		count += ft_manage_null(format);	
	else if(format->dash)
		count += ft_justifyleft(format, str);
	else
		count += ft_justifyright(format, str);
	return (count);
}

static int ft_manage_null(t_format *format)
{
	char *str;
	int	count;

	str = "(null)";
	if (format->dot && format->precision < 6)
		str = "";
	count = 0;
	if (format->dash)
		count += ft_justifyleft(format, str);
	else
		count += ft_justifyright(format, str);
	return (count);
}

static int ft_justifyleft(t_format *format, const char *str)
{
	int count;
	int	str_max;
	int	min_width;

	count = 0;
	min_width = format->width;
	str_max = ft_strlen(str);
	if (format->dot)
		str_max = format->precision;
	count += ft_putnstr(str, str_max);
	count += ft_putnchar(' ', min_width - count);
	return (count);
}

static int ft_justifyright(t_format *format, const char *str)
{
	int count;
	int	str_max;
	int	min_width;

	count = 0;
	min_width = format->width;
	str_max = ft_strlen(str);
	if (format->dot && format->precision < str_max)
		str_max = format->precision;
	count += ft_putnchar(' ', min_width - str_max);
	count += ft_putnstr(str, str_max);
	return (count);
}
