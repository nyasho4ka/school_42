#include "ft_atoi.h"
#include "ft_do_op.h"

int main(int argc, char** argv)
{
    if (argc != 4)
        return (0);
    
    ft_init_op();
    int first = ft_atoi(argv[1]);
    int second = ft_atoi(argv[3]);
    ft_do_op(first, argv[2][0], second);
}