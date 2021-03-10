# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theo <theo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 22:23:39 by theo              #+#    #+#              #
#    Updated: 2021/03/10 22:32:03 by theo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re up

CC = @gcc $(INCLUDES) $(FLAGS)

FLAGS = -Wall -Wextra -Werror

NCURSES = -lncurses

NAME = ./philo_one

INCLUDES = -I ./includes -I ./libft/includes

HEADERS = ./includes/philosopher.h

LIBFT = ./libft/libft.a

SRCS = 	./main.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS) $(OBJS) $(LIBFT) $(HEADERS)
	@printf "\033[032m Philo : Object files Created\033[0m\n"
	@$(CC) $(NCURSES) $(OBJS) -o $(NAME) $(LIBFT)
	@printf "\033[032mPhilo: ./philo_one Created\033[0m\n"

$(LIBFT) :
	@make -C ./libft

clean :
	@rm -f $(OBJS)
	@echo "\033[32mPhilo : Object files Removed\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[32mPhilo : ./philo_one Removed\033[0m"

up : all clean

re : fclean all