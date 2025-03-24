CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

SRC = printf/ft_printf.c	printf/ft_putnbr.c	printf/ft_putchar.c\
		printf/ft_putstr.c	printf/ft_undecimal.c\
		printf/ft_padress.c	printf/ft_lowerad.c	printf/ft_upperad.c\
		pipex.c	bft/ft_bzero.c 	bft/ft_memcpy.c 	bft/ft_split.c\
		bft/ft_calloc.c 	bft/ft_strdup.c 	bft/ft_strlen.c\
		bft/ft_strjoin.c 	bft/ft_substr.c 	open_files.c\
		path_cmd.c	children.c 	bft/ft_strnstr.c 	errors.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o : %.c pipex.h	printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all