# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/02 10:01:16 by kalhanaw          #+#    #+#              #
#    Updated: 2026/04/05 10:44:20 by kalhanaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myPhoneBook
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
HEADERS = colors.hpp \
		  Contact.hpp \
		  PhoneBook_helpers.hpp \
		  PhoneBook_print.hpp \
		  PhoneBook.hpp
SRCS =	Contact.cpp \
		main.cpp \
		PhoneBook_helpers.cpp \
		PhoneBook_print.cpp \
		PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re