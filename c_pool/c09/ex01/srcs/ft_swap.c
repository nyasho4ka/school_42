#ifndef __FT_SWAP__
#define __FT_SWAP__
void ft_swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
#endif