#include "../src/ft_printf.h"

static void ft_rec_display(unsigned long n, const char *base, int base_len)
{
	if ( n >= (unsigned int)base_len)
	{
		ft_rec_display(n / base_len, base , base_len);	
		ft_rec_display(n % base_len, base , base_len);	
	}
	else
		ft_putnchar(base[n], 1);
}

static int ft_get_unumlen_base(unsigned long n, int len_base)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		++len;
		n /= len_base;
	}
	return (len);
}

int	ft_putnbr_uns_base(unsigned long n, const char *base, int base_len)
{
	int count;

	count = ft_get_unumlen_base(n, base_len);
	ft_rec_display(n, base, base_len);
	return (count);
}
