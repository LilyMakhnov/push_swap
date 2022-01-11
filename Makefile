# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esivre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 17:11:34 by esivre            #+#    #+#              #
#    Updated: 2022/01/11 16:07:07 by esivre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS	=	operations.c index.c linkedlist.c main.c sort.c utils.c

OBJS	=	$(SRCS:.c=.o)

DEPS    =	$(SRCS:.c=.d)

FLAGS		=	-Wall -Wextra -Werror

all:			$(NAME)

%.o:	%.c
		gcc ${FLAGS} -MMD -MP -c $< -o ${<:.c=.o}

$(NAME):		$(OBJS)
			gcc $(FLAGS) -o $(NAME) $(OBJS)

clean:
			/bin/rm -f $(OBJS) $(DEPS)

fclean:			clean
			/bin/rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

-include $(DEPS)

