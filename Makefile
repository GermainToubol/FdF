#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 10:59:36 by gtoubol           #+#    #+#              #
#    Updated: 2022/05/25 12:57:06 by gtoubol          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
SRCS =		main.c trace_ray.c
OBJS = 		$(SRCS:.c=.o)

NAME = 		fdf

LIBFT_DIR = libft
LIBFT =		libft/libft.a
MLX_DIR =	minilibx
MLX =		minilibx/minilibx
LIB =		-Llibft -lft -Lminilibx -lmlx -lXext -lX11

CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror
INCLUDES = 	-Ilibft -I./minilibx
RM =		rm -f

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIB)

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< $(LIB)

bonus:		$(NAME_B)

$(LIBFT):
			make -C $(LIBFT_DIR)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)
			make -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME) $(NAME_B)
			make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re bonus
