# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 15:20:16 by mlachheb          #+#    #+#              #
#    Updated: 2021/02/11 11:09:28 by mlachheb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fatal_error.c libft/*.c get_next_line/get_next_line.c first_shell_test.c

#SRCBONUS = 

NAME = minishell.a

OBJSRC = *.o
#OBJSRCBONUS =

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJSRC)
	ranlib $(NAME)
	gcc -Wall -Wextra -Werror minishell.c $(NAME) -o Minishell

bonus:
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJSRC)
	ranlib $(NAME)	

clean:
	/bin/rm -f $(OBJSRC) 

fclean:
	/bin/rm -f $(NAME)
re: fclean all
