# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusman <yusman@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 00:03:07 by yusman            #+#    #+#              #
#    Updated: 2023/05/14 18:57:24 by yusman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC		= moves/pa.c moves/pb.c moves/ra.c moves/rra.c\
moves/sb.c moves/sa.c moves/rr.c moves/rb.c moves/rrb.c\
parsing/checkarg.c parsing/checksort.c parsing/utils.c \
sort/numbers.c \
sort/sort_smallnum.c sort/utils.c push_swap.c\


OBJ		= $(SRC:.c=.o)

LIBFT	= ./libft/libft.a

FT_PRINTF = ./ft_printf/libftprintf.a

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJ)
		make -sC ./ft_printf
		 gcc -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)

$(LIBFT):
		make -C libft all

clean:
		rm -f $(OBJ)
		make clean -sC ./ft_printf
		make -C libft fclean

fclean: clean
		make fclean -sC ./ft_printf
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
