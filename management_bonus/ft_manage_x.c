#include "../src_bonus/ft_printf_bonus.h"

static int	ft_justifyleft(unsigned int n, t_format *format, char *prefix, char *base);
static int	ft_justifyright(unsigned int n, t_format *format, char *prefix, char *base);
static int	ft_get_hexalen(unsigned int n);

int	ft_manage_x(int	n, t_format *format, char c)
{
	int	count;
	char *base;
	char *prefix;

	if (format == NULL)
		return (0);
	count = 0;
	if (format->dot && format->precision == 0 && n == 0)
	{	
		count += ft_putnchar(' ', format->width);
		return (count);
	}
	prefix = "0x";
	base = "0123456789abcdef";
	if (c == 'X')
	{
		prefix = "0X";
		base = "0123456789ABCDEF";
	}
	if (format->dash)
		count += ft_justifyleft(n ,format, prefix, base);
	else
		count += ft_justifyright(n, format, prefix, base);
	return (count);	
}

static	int	ft_justifyleft(unsigned int n, t_format *format, char *prefix, char *base)
{
	int	count;
	int	hexalen;

	count = 0;
	hexalen = ft_get_hexalen(n);
	if (format->dot)
		count += ft_putnchar('0', format->precision - hexalen);
	if (format->hash && n != 0)
		count += ft_putnstr(prefix, 2);
	count += ft_putnbr_uns_base(n, base, 16);
	count += ft_putnchar(' ', format->width - count);
	return (count);
}

static	int	ft_justifyright(unsigned int n, t_format *format, char *prefix, char *base)
{
	int	count;
	int	hexalen;
	int	t_size;
	char pad_char;

	count = 0;
	hexalen = ft_get_hexalen(n);
	pad_char = ' ';
	if (format->zero && !(format->dot))
		pad_char = '0';
	t_size = hexalen;
	if (format->dot && format->precision > hexalen)
		t_size = format->precision;
	if (format->hash && n != 0)
		t_size += 2;
	count += ft_putnchar(pad_char, format->width - t_size);
	count += ft_putnchar('0', format->precision - hexalen);
	if (format->hash && n != 0)
		count += ft_putnstr(prefix, 2);
	count += ft_putnbr_uns_base(n, base, 16);
	return (count);
}

static	int	ft_get_hexalen(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		++len;
		n /= 16;
	}
	return (len);
}
