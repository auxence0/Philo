# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 15:58:44 by asauvage          #+#    #+#              #
#    Updated: 2026/02/17 16:08:55 by asauvage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

NAME = philo

SRC_DIR = src
OBJ_DIR = obj

SRCS = main.c \
	   ft_atol.c \
	   check_arg.c \
	   err_mess.c \
	   ft_putstr_fd.c \
	   malloc_struct.c \
	   clear_all.c \
	   create_philo.c

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