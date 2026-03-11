# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 15:58:44 by asauvage          #+#    #+#              #
#    Updated: 2026/03/11 12:27:22 by asauvage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3 -I.

NAME = philo

SRC_DIR = src
OBJ_DIR = obj

SRCS = main.c \
	   ft_atol.c \
	   err_mess.c \
	   ft_putstr_fd.c \
	   malloc_struct.c \
	   clear_all.c \
	   create_philo.c \
	   parse_struct.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -lpthread $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re