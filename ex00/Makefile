# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gclausse <gclausse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 11:03:18 by gclausse          #+#    #+#              #
#    Updated: 2022/08/17 11:03:18 by gclausse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixedpoint
OBJS = main.cpp Fixed.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror
DBFLAGS = -std=c++98

OBJ=$(OBJS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) $(DBFLAGS) -o $@ -c $<

all: $(NAME)

debug: CFLAGS+=$(DBFLAGS)
debug:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(DBFLAGS) $^ -o $@

clean: 
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug