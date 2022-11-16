NAME		:= rush-02
CC 			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -c

SRC_DIR 	:= ./srcs/
SRC_FILES	:= ft_converter.c ft_fstream.c ft_numbers_dict.c ft_str.c main.c
OBJ_FILES 	:= $(SRC_FILES:.c=.o)
SRSC		:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		:= $(addprefix $(SRC_DIR), $(OBJ_FILES))

HEADER 		:= -I includes/
RM			:= rm -f

all: obj $(NAME)

obj: $(SRCS)

$(SRC_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@ $(HEADER)


$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all $(NAME) obj
