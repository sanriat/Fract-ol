NAME = fract-ol
SRCS = main.c utils.c event_functions.c fractals.c iterate_fractals.c help.c color.c color_set_help.c more_utils.c
OBJS = $(SRCS:.c=.o)
MLX = "https://github.com/42Paris/minilibx-linux.git"
MLX_DIR = minilibx-linux
FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -O3

all: $(MLX_DIR) $(NAME)

$(MLX_DIR):
	@git clone $(MLX)
	@cd $(MLX_DIR) && ./configure

$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror $(OBJS) $(FLAGS) -o $(NAME) -g

bonus: $(MLX_DIR)
	cc -Wall -Wextra -Werror  $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all
