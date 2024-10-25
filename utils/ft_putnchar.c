#include <unistd.h>

int	ft_putnchar(const char c, int n)
{
	int	count;
	int res;

	count = 0;
	while (n > 0)
	{
		res = write(1, &c, 1);
		if (res < 0)
			res = 0;
		count += res;
		--n;
	}
	return (count);
}
