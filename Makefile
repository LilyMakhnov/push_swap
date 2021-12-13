# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esivre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 17:11:34 by esivre            #+#    #+#              #
#    Updated: 2021/12/07 17:11:39 by esivre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS	=	operations.c index.c linkedlist.c main.c sort.c utils.c

OBJS	=	$(SRCS:.c=.o)

FLAGS		=	-Wall -Wextra -Werror

.c.o:
		gcc ${FLAGS} -c $< -o ${<:.c=.o}

all:			$(NAME)

$(NAME):		$(OBJS)
			gcc $(FLAGS) -o $(NAME) $(OBJS)

clean:
			/bin/rm -f $(OBJS) 

fclean:			clean
			/bin/rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
