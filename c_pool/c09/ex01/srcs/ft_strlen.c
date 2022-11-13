#ifndef __FT_STRLEN__
#define __FT_STRLEN__
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
#endif