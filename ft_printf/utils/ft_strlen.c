#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len])
		++len;
	return (len);
}
