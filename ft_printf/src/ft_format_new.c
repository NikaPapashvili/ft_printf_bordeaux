#include "ft_printf.h"

static void	ft_init_format(t_format *format);
static void	ft_affect_flags(t_format *format, const char c);

// Called only when format is checked
t_format *ft_format_new(const char *str, int f_index)
{
	t_format	*newformat;
	int			i;

	newformat = malloc(sizeof(t_format));
	if (newformat == NULL)
		return (NULL);
	ft_init_format(newformat);
	i = f_index + 1;
	while (ft_isflag(str[i]))
	{
		ft_affect_flags(newformat, str[i]);
		++i;
	}
	newformat->width = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		++i;
	if (str[i] == '.')
	{
		newformat->dot = 1;
		newformat->precision = ft_atoi(str + i + 1);
	}
	return (newformat);
}

static void	ft_affect_flags(t_format *format, const char c)
{
	if (format == NULL)
		return ;
	if (c == ' ')
		format->blank = 1;
	else if (c == '-')
		format->dash = 1;
	else if (c == '0')
		format->zero = 1;
	else if (c == '+')
		format->plus = 1;
	else if (c == '#')
		format->hash = 1;
}

static void	ft_init_format(t_format *format)
{
	if (format)
	{
		format->blank = 0;
		format->dash = 0;
		format->zero = 0;
		format->plus = 0;
		format->hash = 0;
		format->dot = 0;
		format->precision = 0;
		format->width = 0;
	}
}
