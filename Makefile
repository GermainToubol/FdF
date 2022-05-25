#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 10:59:36 by gtoubol           #+#    #+#              #
#    Updated: 2022/05/25 18:02:45 by gtoubol          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
SRCS =		main.c trace_line_q1.c trace_line_q2.c trace_line.c				\
			trace_line_straight.c display.c
OBJS = 		$(SRCS:.c=.o)

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

bonus:		$(NAME_B)

$(LIBFT):
			make -C $(LIBFT_DIR)

$(MLX):
			make -C $(MLX_DIR)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)
			make -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME) $(NAME_B)
			make -C $(LIBFT_DIR) fclean
			make -C $(MLX_DIR) clean

re:			fclean all

.PHONY:		all clean fclean re bonus
