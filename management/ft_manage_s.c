#include "../src/ft_printf.h"

int	ft_manage_s(const char *str)
{
	int	count;
	int	len_str;

	count = 0;
	len_str = ft_strlen(str);
	if (str == NULL)
		count += ft_putnstr("(null)", 6);	
	else
		count += ft_putnstr(str, len_str);
	return (count);
}
