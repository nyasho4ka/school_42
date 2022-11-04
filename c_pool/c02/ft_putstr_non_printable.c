#include <unistd.h>

const int FIRST_PRINTABLE = 32;
const int LAST_PRINTABLE = 127;

int is_non_printable(char c)
{
    return c < FIRST_PRINTABLE || c > LAST_PRINTABLE;
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

char convert_number_into_char(int mod)
{
    if (mod >= 0 && mod <= 9)
    {
        return (char)(mod + 48);
    }
    return (char)(mod) + 87;
}

void print_hex_non_printable(char c)
{
    int hex[3] = {'0', '0', '\0'};
    int char_num = (int)c;

    int mod;
    char curr_char;

    int i = 1;
    while (char_num != 0)
    {
        mod = char_num % 16;
        curr_char = convert_number_into_char(mod);
        hex[i] = curr_char;
        char_num = char_num / 16;
        i--;
    }
     
    ft_putchar('\\');
    i = 0;
    while (hex[i])
    {
        ft_putchar(hex[i]);
        i++;
    }
}

void ft_putstr_non_printable(char* str)
{
    int i = 0;
    while (str[i])
    {
        if (is_non_printable(str[i]))
            print_hex_non_printable(str[i]);
        else
            ft_putchar(str[i]);
        i++;
    }
}

int main()
{
    ft_putstr_non_printable("y\tu\v_s\ed\nf");
    ft_putchar('\n');
    return 0;
}