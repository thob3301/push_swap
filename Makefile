# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miteixei <miteixei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 20:31:56 by miteixei          #+#    #+#              #
#    Updated: 2024/10/19 21:29:48 by miteixei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
#-Ofast 
cfiles := push_swap.c \
		deque_manipulation.c \
		destroy.c \
		init_structs.c \
		integrity_check.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		handling.c

ofiles := $(patsubst %.c,%.o,$(cfiles))

cbfiles := checker.c \
		deque_manipulation.c \
		destroy.c \
		init_structs.c \
		integrity_check.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		handling.c

obfiles := $(patsubst %.c,%.o,$(cbfiles))

NAME = push_swap
BONUS = checker
LIBFT = libft/libft.a

$(NAME) : $(ofiles) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(ofiles) $(LIBFT)

$(LIBFT) :
	make -C ./libft

.PHONY : all clean fclean re bonus

all : $(NAME) bonus clean

clean :
	rm -f $(ofiles) $(obfiles)

fclean : clean
	rm -f $(NAME) $(BONUS)

re : fclean $(NAME) bonus

bonus : $(BONUS)

$(BONUS) : $(obfiles) $(LIBFT)
	$(CC) $(CFLAGS) -o $(BONUS) $(obfiles) $(LIBFT)
