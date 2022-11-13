NAME 	:= libft.a
CC 		:= gcc
CFLAGS 	:= -Wall -Wextra -Werror -c

SRC_DIR := ./srcs/
SRC_FILES := ft_putchar.c ft_putstr.c ft_swap.c ft_strlen.c ft_strcmp.c
OBJ_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(SRC_DIR), $(OBJ_FILES))

HEADER 	:= -I includes/
LIBC 	:= ar rc
LIBR 	:= ranlib
RM 		:= rm -f

all: obj $(NAME)

obj: $(SRCS)

$(SRC_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@ $(HEADER)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	$(LIBR) $(NAME)

clean: 
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean all libft.a obj