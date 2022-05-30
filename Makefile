#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 10:59:36 by gtoubol           #+#    #+#              #
#    Updated: 2022/05/30 15:53:56 by gtoubol          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
SRCS =		main.c trace_line_q1.c trace_line_q2.c trace_line.c				\
			trace_line_straight.c display.c color.c fdf_errors.c fdf_parse.c\
			fdf_map.c fdf_extend_map.c fdf_map_utils.c fdf_img_utils.c fdf_quit.c\
			fdf_zoom.c fdf_move.c fdf_hooks.c fdf_generate_mapcover.c fdf_set_coordinates.c
OBJS = 		$(SRCS:.c=.o)
DEPS =		$(SRCS:.c=.d)

NAME = 		fdf

LIBFT_DIR = libft
LIBFT =		libft/libft.a
MLX_DIR =	minilibx
MLX =		minilibx/libmlx_Linux.a
LIB =		-Llibft -lft -Lminilibx -lmlx -lXext -lX11 -lm

CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror -O3
INCLUDES = 	-Ilibft -I./minilibx
RM =		rm -f

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIB)

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.d:		%.c
			@set -e; rm -f $@; \
			$(CC) -MM $(CFLAGS) $(INCLUDES) $< > $@.$$$$; \
			sed 's,\($*\)\.	o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
			rm -f $@.$$$$

bonus:		$(NAME_B)

$(LIBFT):
			make -C $(LIBFT_DIR)

$(MLX):
			make -C $(MLX_DIR)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS) $(DEPS)
			make -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME) $(NAME_B)
			make -C $(LIBFT_DIR) fclean
			make -C $(MLX_DIR) clean

re:			fclean all

.PHONY:		all clean fclean re bonus
include		$(DEPS)
