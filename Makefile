NAME = read_file

SRC = main.c read_file.c get_next_line.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra

INCLUDES = -I .

ATTACH = -L ./libft -lft

all: $(NAME)

$(NAME):
	gcc $(CFLAG) $(INCLUDES) -c $(SRC)
	gcc $(CFLAG) -o $(NAME)	$(OBJ) $(ATTACH)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all