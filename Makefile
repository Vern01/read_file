NAME = read_file

SRC = main.c read_file.c get_next_line.c add_to_array.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra

MAKE_LIBFT = make -C libft/

INCLUDES = -I . -I libft

ATTACH = -L ./libft -lft

all: $(NAME)

$(NAME):
	$(MAKE_LIBFT)
	gcc $(CFLAG) $(INCLUDES) -c $(SRC)
	gcc $(CFLAG) -o $(NAME)	$(OBJ) $(ATTACH)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
