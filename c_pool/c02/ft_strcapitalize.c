#include <printf.h>

const int CASE_DIFF = 'a' - 'A';

int is_lower(char c)
{
    return c >= 'a' && c <= 'z';
}

int is_upper(char c)
{
    return c >= 'A' && c <= 'Z';
}

int is_numeric(char c)
{
    return c >= '0' && c <= '9';
}

int is_alpha(char c)
{
    return is_lower(c) || is_upper(c) || is_numeric(c);
}


char* ft_strcapitalize(char* str)
{
    int i = 0;
    int prev_space = 1;
    while (str[i])
    {
        if (!is_alpha(str[i]))
            prev_space = 1;
        else if (prev_space)
        {
            if (is_lower(str[i]))
                str[i] = str[i] - CASE_DIFF;
            prev_space = 0;
        }
        else if (is_upper(str[i]))
            str[i] = str[i] + CASE_DIFF;
        i++;
    }
    return str;
}

int main()
{
    char mix_string[] = {"  hELL0 my lAdY ? 42points some-word; like+this+one\n"};
    ft_strcapitalize(mix_string);
    printf("%s", mix_string);
    return 0;
}