NAME		:= do-op
CC			:= gcc
CFLAGS 		:= -Wall -Wextra -Werror -c

SRC_DIR		:= ./srcs/
SRC_FILES 	:= ft_do_op.c ft_atoi.c main.c
OBJ_FILES	:= $(SRC_FILES:.c=.o)
SRCS		:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		:= $(addprefix $(SRC_DIR), $(OBJ_FILES))

HEADER		:= -I includes/
RM			:= rm -f

all: objs $(NAME)

objs: $(SRCS)

$(SRC_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@ $(HEADER)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all objs $(NAME) clean fclean re