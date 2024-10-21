#include "../src/ft_printf.h"

int ft_manage_c(const char c, t_format *format)
{
	int count;

	if (format == NULL)
		return (0);
	count = 0;
	if (format->dash)
	{
		count += ft_putnchar(c, 1);
		count += ft_putnchar(' ', format->width - count);
	}
	else
	{
		count += ft_putnchar(' ', format->width - 1);
		count += ft_putnchar(c, 1);
	}
	return (count);
}
