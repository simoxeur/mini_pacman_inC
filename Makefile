NAME	= pac_man

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS = srcs/play.c srcs/animation.c srcs/parse.c srcs/main.c srcs/ft_error.c srcs/ft_itoa.c \
	   srcs/tools.c srcs/input_handle.c srcs/put_str.c srcs/check_ways.c srcs/map_check.c \
	   srcs/graphic_handle.c srcs/flood_fill.c srcs/clean_up.c srcs/movement_handle.c
OBJS = ${SRCS:.c=.o}

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
endif

ifeq ($(UNAME_S), Darwin)
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS)
	@$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ Compilation finished!"

%.o: %.c pac_man.h
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "🧹 Objects removed."

fclean: clean
	@rm -f $(NAME)
	@echo "🧹 Executable removed."

re: fclean all

.PHONY: all clean fclean re