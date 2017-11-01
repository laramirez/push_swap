# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lramirez <lramirez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/21 16:48:26 by lramirez          #+#    #+#              #
#    Updated: 2017/11/01 11:58:37 by lramirez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER_NAME = checker

LIBFT = ./libft/libft.a
SRC_DIR = ./push_swap_dir/sources/
CHECKER_SRC_DIR = ./checker_dir/sources/
OBJ_DIR = ./push_swap_dir/objects/
CHECKER_OBJ_DIR = ./checker_dir/objects/
_OBJ =	main.o \
		compute_solution.o \
		stack_util.o \
		instructions.o
		# list_util.o \
		# tools.o
_OBJ_CHECKER =	main.o \
				checker_util.o \
				get.o \
				instructions.o \
				display_and_free.o
OBJ = $(patsubst %, $(OBJ_DIR)%, $(_OBJ))
OBJ_CHECKER = $(patsubst %, $(CHECKER_OBJ_DIR)%, $(_OBJ_CHECKER))

CFLAGS = -Wall -Wextra -Werror -O3
VPATH = sources:includes

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@cc $(CFLAGS) -c -Iincludes -o $@ $<

$(CHECKER_OBJ_DIR)%.o : $(CHECKER_SRC_DIR)%.c
	@cc $(CFLAGS) -c -Iincludes -o $@ $<

all: make_libft $(NAME) $(CHECKER_NAME)

$(NAME) : $(OBJ) $(LIBFT)
	@gcc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(CHECKER_NAME) : $(OBJ_CHECKER)
	@gcc $(CFLAGS) $(OBJ_CHECKER) $(LIBFT) -o $(CHECKER_NAME)

$(OBJ) : ./push_swap_dir/includes/push_swap.h | $(OBJ_DIR)

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_CHECKER) : ./checker_dir/includes/checker.h | $(CHECKER_OBJ_DIR)

$(CHECKER_OBJ_DIR) :
	@mkdir $(CHECKER_OBJ_DIR)

make_libft:
	@make -C ./libft

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(CHECKER_OBJ_DIR)
	@make -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(CHECKER_NAME)
	@make -C ./libft fclean

re: fclean all

.PHONY: clean fclean re
