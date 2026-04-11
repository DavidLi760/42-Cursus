NAME    = so_long
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Imlx -g3
LFLAGS  = -Lmlx -lmlx -lX11 -lXext -lXrandr -lm
LIBFT   = libft/libft.a
PRINTF  = ft_printf/libftprintf.a
MLX		= mlx/libmlx.a
SRC     = main.c parsing.c parsing2.c utils.c declare1.c declare2.c init.c press.c player1.c player2.c death.c win.c
OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME) $(LFLAGS)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf

$(MLX):
	make -C mlx

clean:
	$(MAKE) clean -C libft
	$(MAKE) clean -C ft_printf
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf
	rm -f $(NAME)

re: fclean all
	$(MAKE) re -C libft
	$(MAKE) re -C ft_printf
	rm -rf $(OBJ)

.PHONY: all clean fclean re
