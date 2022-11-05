#include <stdio.h>
#include <unistd.h>

const unsigned int CHUNK_SIZE = 16;
const char HEX_MAP[] = "0123456789abcdef";

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_address(const char* char_ptr)
{
    unsigned long ptr_to_num = (unsigned long) char_ptr;

    ft_putchar('0');
    ft_putchar('x');

    char add[16];

    int i = 0;
    while (ptr_to_num)
    {
        add[i] = HEX_MAP[ptr_to_num % 16];
        ptr_to_num /= 16;
        i++;
    }

    for (int k = 0; k < 16 - i; k++)
    {
        ft_putchar('0');
    }

    while (i > 0)
    {
        i--;
        ft_putchar(add[i])        ;
    }
    ft_putchar(':');
}

void print_char_to_hex(char c)
{
    int hex_num[2];
    int digit = 0;
    while (c)
    {
        hex_num[digit] = c % 16;
        c = c / 16;
        digit++;
    }
    for (int i = 1; i >= 0; i--)
    {
        ft_putchar(HEX_MAP[hex_num[i]]);
    }
}

void ft_print_hex_content(const char *str, unsigned int char_num, unsigned int space_num)
{
    for (unsigned int i = 0; i < char_num; i++)
    {
        if (i % 2 == 0)
            ft_putchar(' ');        
        print_char_to_hex(str[i]);
    }

    for (unsigned int i = 0; i < space_num; i++)
    {
        ft_putchar(' ');
    }
}

int is_printable(char c)
{
    return c >= 32 && c <= 127;
}

void ft_print_char_content(const char* str, unsigned int char_num, unsigned int space_num)
{
    ft_putchar(' ');
    for (unsigned int i = 0; i < char_num; i++)
    {
        if (is_printable(str[i]))
            ft_putchar(str[i]);
        else
            ft_putchar('.');
    }
    
    for (unsigned int i = 0; i < space_num; i++)
        ft_putchar(' ');
    ft_putchar('\n');
}

void* ft_print_memory(void* addr, unsigned int size)
{
    char* char_ptr = addr;
    for (unsigned int chunk = 0; chunk < size; chunk += CHUNK_SIZE)
    {
        ft_print_address(char_ptr + chunk);
        unsigned int char_num = chunk + CHUNK_SIZE > size ? size - chunk : CHUNK_SIZE;
        unsigned int space_num = CHUNK_SIZE - char_num;
        ft_print_hex_content(char_ptr + chunk, char_num, space_num);
        ft_print_char_content(char_ptr + chunk, char_num, space_num); 
    }
    return addr;
}

int main()
{
    char str[] = "Bonjour les aminches\t\n\tc est  fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n \0";
    ft_print_memory(str, 92);
}