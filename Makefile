NAME = fdf

SRCS =	srcs/main.c \
		srcs/get_next_line.c \

FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc -o $(NAME) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit libft/libft.a

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all