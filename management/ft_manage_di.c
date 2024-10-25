#include "../src/ft_printf.h"

int	ft_manage_di(int nb)
{
	int		count;
	long	n;

	count = 0;
	n = nb;
	if (n < 0)
	{
		count += ft_putnchar('-', 1);
		n = -n;
	}
	count += ft_putnbr_uns_base(n, "0123456789", 10);
	return (count);
}
