#include "../src/ft_printf.h"

int	ft_manage_u(unsigned int n)
{
	int	 count ;

	count = 0;
	count += ft_putnbr_uns_base(n, "0123456789", 10);
	return (count);
}
