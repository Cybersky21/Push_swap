# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 19:02:20 by acrooks           #+#    #+#              #
#    Updated: 2019/08/21 14:26:51 by acrooks          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker

SRC1 = srcs/ab_push.c srcs/ab_rev_rotate.c srcs/ab_rotate.c srcs/ab_swap.c \
srcs/output_free.c srcs/sorting.c srcs/sorting1.c srcs/sorting2.c \
srcs/sorting3.c srcs/validate_nbr.c

OBJ1 = push_swap.o ab_push.o ab_rev_rotate.o ab_rotate.o ab_swap.o \
output_free.o sorting.o sorting1.o sorting2.o sorting3.o validate_nbr.o

OBJ2 = checker.o checker1.o ab_push.o ab_rev_rotate.o ab_rotate.o ab_swap.o \
output_free.o validate_nbr.o

FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libftprintf.a

all: $(NAME1) $(NAME2)

$(NAME1):
		@make re -C libft/
		@gcc -c -g $(SRC1) srcs/push_swap.c
		@gcc $(LIBFT) $(FLAGS) $(OBJ1) -o $(NAME1)

$(NAME2):
		@gcc -c -g srcs/checker.c srcs/checker1.c
		@gcc $(LIBFT) $(FLAGS) $(OBJ2) -o $(NAME2)

clean:
		make clean -C libft
		@rm -f $(OBJ1)
		@rm -f checker.o checker1.o

fclean: clean
		make fclean -C libft
		@rm -f push_swap
		@rm -f checker

re: fclean all
