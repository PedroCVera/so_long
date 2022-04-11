# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 16:26:20 by ralves-g          #+#    #+#              #
#    Updated: 2022/04/11 16:28:44 by pcoimbra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -Imlx
MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit
RM			= rm -f

NAME		= so_long

#NAME_B		= checker

INCLUDE		= get_next_line/get_next_line.h so_long.h
SRCS		= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				ft_solong.c ft_mpche.c ft_itoa.c ft_strdup.c ft_utils.c \
				ft_utils2.c ft_utils3.c ft_glob.c ft_utils4.c

OBJS		= $(SRCS:.c=.o)

all:		$(SRCS) $(OBJS)
			$(CC) $(MLXFLAGS) $(SRCS) -o $(NAME)
#			$(CC) $(CFLAGS) $(MLXFLAGS) $(SRCS) -c

#bonus:		$(SRCS_B) $(OBJS_B)
#			$(CC) $(CFLAGS) $(SRCS_B) -o $(NAME_B)
#			$(CC) $(CFLAGS) $(SRCS_B) -c

clean:
			$(RM) $(OBJS)
#			$(OBJS_B)

fclean:		clean
			$(RM) $(NAME)
#			$(NAME_B)

re:			fclean all
