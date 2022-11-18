#ifndef __FT_DO_OP__
#define __FT_DO_OP__

typedef struct s_operator {
    char op_char;
    void (*f)(int, int);
} t_operator;

t_operator operators[5];

void ft_sum(int, int);
void ft_sub(int, int);
void ft_mul(int, int);
void ft_div(int, int);
void ft_mod(int, int);
void ft_init_op();
void ft_do_op(int, char, int);

#endif