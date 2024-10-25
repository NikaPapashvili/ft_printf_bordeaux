#include "../src_bonus/ft_printf_bonus.h"

static int	ft_justifyleft(unsigned long adr, t_format *format);
static int	ft_justifyright(unsigned long adr, t_format *format);
static int	ft_manage_null(t_format *format);
static int	ft_get_hexalen(unsigned long n);

int	ft_manage_p(void *ptr, t_format *format)
{
	unsigned long	adr;
	int				count;

	count = 0;
	adr = (unsigned long)ptr;
	if (ptr == NULL)
		count += ft_manage_null(format);
	else if (format->dash)
		count += ft_justifyleft(adr, format);
	else
		count += ft_justifyright(adr, format);
	return (count);
}

static int	ft_get_hexalen(unsigned long n)
{
	int	hexalen;

	if (n == 0)
		return (1);
	hexalen = 0;
	while (n)
	{
		++hexalen;
		n /= 16;
	}
	return (hexalen);
}

static int	ft_justifyright(unsigned long adr, t_format *format)
{
	int	count;
	int	hexalen;
	int	min_width;
	int	precision;
	int	zero_padding;

	count = 0;
	min_width = format->width;
	precision = format->precision;
	hexalen = ft_get_hexalen(adr);
	zero_padding = 0;
	if (format->dot)
		zero_padding = precision - hexalen;
	if (zero_padding < 0)
		zero_padding = 0;
	count += ft_putnchar(' ', min_width - 2 - hexalen);
	count += ft_putnstr("0x", 2);
	count += ft_putnchar('0', zero_padding);
	count += ft_putnbr_uns_base(adr, "0123456789abcdef", 16);
	return (count);
}

static int	ft_justifyleft(unsigned long adr, t_format *format)
{
	int	count;
	int	hexalen;
	int	min_width;
	int	precision;

	count = 0;
	min_width = format->width;
	precision = format->precision;
	hexalen = ft_get_hexalen(adr);
	count += ft_putnstr("0x", 2);
	if (format->dot)
		count += ft_putnchar('0', precision - hexalen);
	count += ft_putnbr_uns_base(adr, "0123456789abcdef", 16);
	count += ft_putnchar (' ', min_width - count);
	return (count);
}

static int	ft_manage_null(t_format *format)
{
	int	count;
	int	min_width;

	count = 0;
	min_width = format->width;
	if (format->dash)
	{
		count += ft_putnstr("(nil)", 5);
		count += ft_putnchar(' ', min_width - count);
	}
	else
	{
		count += ft_putnchar(' ', min_width - 5);
		count += ft_putnstr("(nil)", 5);
	}
	return (count);
}
