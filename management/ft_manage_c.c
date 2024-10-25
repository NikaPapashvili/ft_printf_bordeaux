#include "../src/ft_printf.h"

int ft_manage_c(const char c)
{
	int count;

	count = 0;
	count += ft_putnchar(c, 1);
	return (count);
}
