NAME			=	cub3D

HEADER			=	includes
LIB_HEADER		=	libft/
DIR_SRCS		=	srcs/
DIR_GNL			=	gnl/
DIR_ENGINE		=	srcs/engine/
DIR_PARSING		=	srcs/parsing/
DIR_UTILS		=	srcs/utils/
DIR_ERRORS		=	srcs/errors/
CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Werror -Wextra -O3 -g -I.

SRCS			=	main.c \
					\
					$(DIR_SRCS)keyboard.c			$(DIR_SRCS)minimap_draw.c \
					$(DIR_SRCS)screenshot.c			$(DIR_SRCS)init_params.c \
					\
					$(DIR_GNL)get_next_line.c		$(DIR_GNL)get_next_line_utils.c \
					\
					$(DIR_PARSING)open_map.c		$(DIR_PARSING)edit_map.c \
					$(DIR_PARSING)data_load.c		$(DIR_PARSING)data_load_more.c \
					\
					$(DIR_ENGINE)raycasting.c		$(DIR_ENGINE)draw.c \
					$(DIR_ENGINE)additional_funcs.c \
					\
					$(DIR_UTILS)utils.c				$(DIR_UTILS)utils_2.c \
					$(DIR_UTILS)utils_3.c \
					\
					$(DIR_ERRORS)errors.c

OBJS			= $(SRCS:.c=.o)

LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
MLX				= libmlx.dylib



.PHONY:			all clean fclean re

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS) $(HEADER)
				$(CC) ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}


$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .

clean:
				@$(MAKE) -C mlx clean
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)


