# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/29 14:43:32 by hkhouzim          #+#    #+#              #
#    Updated: 2026/02/12 16:11:02 by hkhouzim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==========================
# Project
# ==========================
NAME = push_swap
AR_LIB = libpush.a

# ==========================
# Compiler
# ==========================
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

# ==========================
# Headers
# ==========================
HEADER = push_swap.h

# ==========================
# Source files
# ==========================
SRCS = main.c \
       algorithms/small_sort.c \
       algorithms/radix_sort.c \
       core/index.c \
       core/init_stack.c \
       core/stack_to_array.c \
       helpers/ft_atoll.c \
       helpers/ft_isdigit.c \
       helpers/ft_lstadd_front.c \
       helpers/ft_lstlast.c \
       helpers/ft_lstnew.c \
       helpers/ft_lstsize.c \
       helpers/ft_putstr.c \
       helpers/ft_split.c \
       helpers/ft_strcpy.c \
       helpers/ft_strlen.c \
       helpers/ft_strncmp.c \
       helpers/ft_strcmp.c \
       helpers/valid_input_string.c \
       helpers/count_elements.c \
       helpers/parse_simple.c \
       helpers/parse_multiple.c \
       helpers/valid_input_argv.c \
       helpers/sort_arr.c \
       helpers/error_exit.c \
       helpers/is_sorted.c \
       helpers/free_stack.c \
       helpers/ft_lstadd_back.c \
       operations/push.c \
       operations/reverse_rotate.c \
       operations/rotate.c \
       operations/swap.c \
       operations/push_collection.c \
       operations/swap_collection.c \
       operations/reverse_rotate_collection.c \
       operations/rotate_collection.c

OBJS = $(SRCS:.c=.o)

# ==========================
# Build targets
# ==========================
all: $(NAME)

# Build the push_swap executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Build object files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Build static library
lib: $(OBJS)
	ar rcs $(AR_LIB) $(OBJS)

# ==========================
# Clean
# ==========================
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(AR_LIB)

re: fclean all

.PHONY: all clean fclean re lib
