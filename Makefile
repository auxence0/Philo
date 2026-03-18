# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 15:58:44 by asauvage          #+#    #+#              #
#    Updated: 2026/03/18 13:42:29 by asauvage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -I. -pthread 

NAME = philo

SRC_DIR = src
OBJ_DIR = obj

SRCS = main.c \
	   ft_atol.c \
	   err_mess.c \
	   malloc_struct.c \
	   clear_all.c \
	   create_philo.c \
	   parse_struct.c \
	   ft_usleep.c \
	   check_mutex.c \
	   monitoring.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re