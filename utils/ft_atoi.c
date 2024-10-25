#include "../src/ft_printf.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;

	if (str == NULL)
		return (0);
	res = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - 48);
		++i;
	}
	return (res);
}
