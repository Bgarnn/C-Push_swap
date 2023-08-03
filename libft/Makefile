# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kburalek <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 13:29:22 by kburalek          #+#    #+#              #
#    Updated: 2023/02/22 13:29:25 by kburalek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME =	libft.a
SRC =	ft_strlen.c ft_strdup.c ft_substr.c ft_strjoin.c ft_split.c ft_putstr_fd.c

OBJS = $(SRC:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

%o: %c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS) 

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re