#!/bin/bash

file_names=("ft_putchar" "ft_putstr" "ft_strcmp" "ft_strlen" "ft_swap")

for file in ${file_names[@]}
do
    rm -f "${file}.o"
done

for file in ${file_names[@]}
do
    gcc -c -Wall -Wextra -Werror "${file}.c"
done

link_files="${file_names[0]}.o"

for file in ${file_names[@]:1}
do
    link_files+=" ${file}.o"
done

ar rc libft.a ${link_files}
ranlib libft.a

for file in ${file_names[@]}
do
    rm -f "${file}.o"
done