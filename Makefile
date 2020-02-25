NAME	= fillit

SRC		= ./src/main.c  \
		  ./src/set_zero.c \
		  ./src/output.c  \
		  ./src/map.c   \
		  ./src/ft_solution.c \
		  ./src/ft_valid.c \
		  ./src/ft_input.c \
		  ./src/ft_boardsize.c \
		  ./src/ft_memdel.c \
		  ./src/ft_putchar.c  \
		  ./src/ft_strdel.c  \
		  ./src/ft_strjoin.c \
		  ./src/ft_strlen.c \
		  ./src/ft_strnew.c\
		  ./src/ft_strsub.c \
		  ./src/ft_memset.c \
		  ./src/ft_memalloc.c \
		  ./src/ft_free_map.c \



OBJ		= $(SRC:.c=.o)

INCLUDE = ./includes

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I./$(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I$(INCLUDE)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(OBJ)

re: fclean all
