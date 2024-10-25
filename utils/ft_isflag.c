int ft_isflag(const char c)
{
	int res;

	res = 0;
	res += (c == '-');
	res += (c == '0');
	res += (c == '+');
	res += (c == ' ');
	res += (c == '#');
	return (res);
}