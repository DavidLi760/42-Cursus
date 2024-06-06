# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotavare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 03:50:25 by jotavare          #+#    #+#              #
#    Updated: 2024/06/06 10:52:18 by davli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
PRINTF = libft/ft_printf/libftprintf.a

CC = cc
FLAGS = -Wall -Werror -Wextra

SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)


all: $(SERVER) $(CLIENT)

$(SERVER) $(CLIENT): $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT) $(PRINTF)
		${CC} ${FLAGS} ${OBJS_SERVER} ${LIBFT} ${PRINTF} -o ${SERVER}
		${CC} ${FLAGS} ${OBJS_CLIENT} ${LIBFT} ${PRINTF} -o ${CLIENT}

$(LIBFT):
		make -C ./libft
		make -C ./libft/ft_printf

clean:
		make clean -C ./libft
		make clean -C ./libft/ft_printf
		rm -rf ${OBJS_SERVER} ${OBJS_CLIENT}

fclean:	clean
		make fclean -C ./libft
		make fclean -C ./libft/ft_printf
		rm -rf $(SERVER) $(CLIENT)

re:	fclean all
