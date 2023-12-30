# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 14:39:40 by plgol.perso       #+#    #+#              #
#    Updated: 2023/12/01 14:39:43 by plgol.perso      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
RM := rm -f

# CFLAGS := -Wall -Werror -Wextra -fsanitize=address -fsanitize=undefined
CFLAGS := -Wall -Werror -Wextra -O3

NAME := push_swap

INC_DIR := ./plib
SRC_DIRS := src
SRCS := $(wildcard $(addsuffix /*.c,$(SRC_DIRS)))
OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re plib

all: $(NAME)

$(NAME): $(OBJS) plib
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(INC_DIR) -lplib

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

plib:
	$(MAKE) -C $(INC_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(INC_DIR) fclean

re: fclean all
