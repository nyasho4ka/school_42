#include <stdio.h>
#include <unistd.h>

const char NEW_LINE = '\n';

int min_str(char* str1, char* str2)
{
    int i = 0;
    while (str1[i] && str2[i])
    {
        if (str1[i] < str2[i])
        {
            return 1;
        }
        i++;
    }
    if (str2[i] != '\0')
        return 1;

    return 0;
}

void ft_print_param(char *param)
{
    int char_count = 0;
    while (param[char_count])
    {
        char_count++;
    }
    write(1, param, char_count);
    write(1, &NEW_LINE, 1);
}

void ft_sort_params(int argc, char** argv)
{
    char* temp;
    for (int i = 1; i < argc - 1; i++)
    {
        for (int j = i + 1; j < argc; j++)
        {
            if (min_str(argv[j], argv[i]))
            {
                temp = argv[i];
                argv[i] = argv[j];
                argv[j] = temp;
            }
        }
    }
    for (int i = 1; i < argc; i++)
    {
        ft_print_param(argv[i]);
    }
}

int main(int argc, char** argv)
{
    ft_sort_params(argc, argv);
    return (0);
}
