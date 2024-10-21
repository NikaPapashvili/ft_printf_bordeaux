#include "ft_printf.h"
//#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list 	args;
	t_format	*format;
	int			len_outputs;
	int			is_error;
	int			i;

	if (str == NULL)
		return (-1);
	va_start(args, str);
	is_error = 0;
	len_outputs = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_check_format(str, i))
		{
			len_outputs += ft_putnchar(str[i], 1);
			++i;
			continue;
		}
		format = ft_format_new(str, i);
		if(format)
		{
			len_outputs += ft_format(str, i, args, format);
			free(format);
		}
		if (len_outputs == -1)
			is_error = 1;
		i = ft_skip_format(str, i);	
	}
	if (is_error)
		return (-1);
	return (len_outputs);
}/*
#include <stdio.h>
int main(int ac, char const **av)
{
	int res_real;
	int res_fake;

	(void)ac;
	//(void)res_real;
	res_fake = ft_printf(av[1], atoi(av[2]));
	printf("\n");
	res_real = printf(av[1], atoi(av[2]));
	printf("\nres_fake: %d", res_fake);
	printf("\nres_real: %d\n", res_real);
	return 0;
}*/