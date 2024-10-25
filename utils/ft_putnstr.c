#include "../src/ft_printf.h"

int ft_putnstr(const char *str, int n)
{
	int count;
	int i;

	if (str == NULL)
		return (0);
	i = 0;
	count = 0;
	while (i < n && str[i])
	{
		count += ft_putnchar(str[i], 1);
		++i;
	}
	return (count);
}