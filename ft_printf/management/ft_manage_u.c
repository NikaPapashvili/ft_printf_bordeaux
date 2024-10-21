#include "../src/ft_printf.h"


static	int	ft_get_unumlen(unsigned int n);
static	int	ft_justifyleft(unsigned int n, t_format *format);
static	int	ft_justifyright(unsigned int n, t_format *format);

int	ft_manage_u(unsigned int n, t_format *format)
{
	int	 count ;

	if (format == NULL)
		return (0);
	count = 0;
	if (format->dash)
		count += ft_justifyleft(n, format);
	else
		count += ft_justifyright(n, format);
	return (count);
}

static	int	ft_justifyleft(unsigned int n, t_format *format)
{
	int	count;
	int	unum_len;

	count = 0;
	unum_len = ft_get_unumlen(n);
	if (format->dot)
		count += ft_putnchar('0', format->precision - unum_len);
	count += ft_putnbr_uns_base(n, "0123456789", 10);
	count += ft_putnchar(' ', format->width - count);
	return (count);
}

static	int	ft_justifyright(unsigned int n, t_format *format)
{
	int	count;
	int	unum_len;
	int	t_size;
	char pad_char;

	count = 0;
	unum_len = ft_get_unumlen(n);
	pad_char = ' ';
	if (format->zero && !(format->dot))
		pad_char = '0';
	t_size = unum_len;
	if (format->dot && format->precision > unum_len)
		t_size = format->precision;
	count += ft_putnchar(pad_char, format->width - t_size);
	count += ft_putnchar('0', format->precision - unum_len);
	count += ft_putnbr_uns_base(n, "0123456789", 10);
	return (count);
}

static	int	ft_get_unumlen(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}
