# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 15:20:16 by mlachheb          #+#    #+#              #
#    Updated: 2021/02/23 15:27:40 by mlachheb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fatal_error.c test_functions.c command_parser.c fill_command.c check_functions/*.c allocation_functions.c libft/*.c get_next_line/get_next_line.c commands_list/*.c

#SRCBONUS = 

NAME = minishell.a

OBJSRC = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJSRC)
	ranlib $(NAME)
	gcc -g -Wall -Wextra -Werror $(MAIN) $(NAME) -o Minishell

bonus:
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJSRC)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJSRC) 

fclean:
	/bin/rm -f $(NAME)
re: fclean all

sanitize:
	gcc -Wall -Wextra -Werror -fsanitize=address -c $(SRC)
	ar rc $(NAME) $(OBJSRC)
	ranlib $(NAME)
	gcc -g -Wall -Wextra -Werror -fsanitize=address $(MAIN) $(NAME) -o Minishell

noflags:
	gcc -c -g $(SRC)
	ar rc $(NAME) $(OBJSRC)
	ranlib $(NAME)
	gcc -g $(MAIN) $(NAME) -o Minishell