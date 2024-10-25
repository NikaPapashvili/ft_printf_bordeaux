#include <stdlib.h>

int ft_occ_c(const char *str, const char c)
{
    int i;
    int count;
    
    if (str == NULL)
        return (0);
    i = 0;
    count = 0;
    while (str[i])
    {
        count += (str[i] == c);
        ++i;
    }
    return (count);
}
