#include "../src/ft_printf_bonus.h"

static int	ft_justifyleft(long n, t_format *format);
static int	ft_justifyright(long n, t_format *format);
static int	ft_get_numlen(long n);

int	ft_manage_di(int n, t_format *format)
{
	int	count;

	if (format == NULL)
		return (0);
	count = 0;
	if (format->dash)
		count += ft_justifyleft(n, format);
	else
		count += ft_justifyright(n , format);
	return (count);
}

static int	ft_get_numlen(long n)
{
	int len;

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

static int	ft_justifyleft(long n, t_format *format)
{
	int	count;
	int min_width;
	int	precision;
	int	num_len;

	count = 0;
	min_width = format->width;
	precision = format->precision;
	num_len = ft_get_numlen(n);
	if (n < 0)
	{
		count += ft_putnchar('-', 1);
		n = -n;
	}
	else if (format->plus)
		count += ft_putnchar('+', 1);
	else if (format->blank)
		count += ft_putnchar(' ', 1);
	if (format->dot)
		count += ft_putnchar('0', precision - num_len);
	count += ft_putnbr_uns_base(n, "0123456789", 10);
	count += ft_putnchar(' ', min_width - count);
	return (count);
}

static int	ft_justifyright(long n, t_format *format)
{
	int	count;
	int	t_len;
	int	num_len;
	int	zero_pads;
	char prefix;

	count = 0;
	num_len = ft_get_numlen(n);
	zero_pads = 0;
	prefix = 0;
	if (n < 0)
	{
		prefix = '-';
		n = -n;
	}
	else if (format->plus)
		prefix = '+';
	else if (format->blank)
		prefix = ' ';
	if (format->dot && format->precision > num_len)
		zero_pads = format->precision - num_len;
	else if (!format->dot && format->width > num_len)
	{
		zero_pads = format->width - num_len;
		if (prefix)
			--zero_pads;
	}
	t_len = zero_pads + num_len;
	if (prefix)
		++t_len;
	count += ft_putnchar(' ', format->width - t_len);
	if (prefix)
		count += ft_putnchar(prefix, 1);
	count += ft_putnchar('0', zero_pads);
	count += ft_putnbr_uns_base(n, "0123456789", 10);
	return (count);
}
