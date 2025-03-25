CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

SRC = 	pipex.c	bft/ft_bzero.c 	bft/ft_memcpy.c 	bft/ft_split.c\
		bft/ft_calloc.c 	bft/ft_strdup.c 	bft/ft_strlen.c\
		bft/ft_strjoin.c 	bft/ft_substr.c 	open_files.c\
		path_cmd.c	children.c 	bft/ft_strnstr.c 	errors.c 	bft/ft_putstr_fd.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o : %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all