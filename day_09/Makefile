# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/07 15:40:16 by kmira             #+#    #+#              #
#    Updated: 2019/12/09 14:29:39 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = day_09
FLAGS = -Wall -Wextra -Werror

FILES = \
	main \
	operations \
	utils \

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(FLAGS) $(SRCS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
