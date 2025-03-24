NAME	= so_long

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRCS =			srcs/play.c				srcs/animation.c		srcs/parse.c			\
				srcs/main.c				srcs/ft_error.c			srcs/ft_itoa.c			\
				srcs/tools.c			srcs/input_handle.c		srcs/put_str.c			\
				srcs/check_ways.c 		srcs/map_check.c		srcs/graphic_handle.c	\
				srcs/flood_fill.c		srcs/clean_up.c			srcs/movement_handle.c	\


OBJS	=		${SRCS:.c=.o}

all: $(NAME)

# on mac os
# %.o:%.c so_long.h
# 	$(CC) ${CFLAGS}  -Imlx -c $< -o $@

# on linux
%.o:%.c so_long.h
	@$(CC) ${CFLAGS}  -I/usr/include -Imlx -O3 -c $< -o $@

# on linux
$(NAME): 		${OBJS}
	@$(CC) ${OBJS} -Lmlx -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}
	@echo finished

# on mac Os
# $(NAME): 		${OBJS}
# 	$(CC) ${OBJS} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
	@rm -f ${OBJS} ${OBJS_B}
	@echo objects removed

fclean: 	clean
	@rm -f $(NAME) $(NAME_B)
	@rm -rf obj
	@echo removed ${NAME}

re:		fclean all

.PHONY: clean