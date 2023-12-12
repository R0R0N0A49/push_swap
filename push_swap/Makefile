#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trebours <trebours@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 14:47:54 by trebours          #+#    #+#              #
#    Updated: 2023/12/08 12:41:02 by trebours         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=push_swap.a
CC=cc
CFLAG= -Werror -Wall -Wextra
SRCS= push_swap.c ft_printf/ft_printf.c ft_printf/ft_printf_utils.c display.c
OBJS=$(SRCS:.c=.o)
RM=rm -f
ARRC=ar -rc

all: $(NAME)
$(NAME): $(OBJS)
	@$(ARRC) $(NAME) $(OBJS)
	@echo "Successful compilation"
%.o: %.c
	@$(CC) $(CFLAG) -c $< -o $@
clean:
	@$(RM) $(OBJS)
	@echo "Files clean"
fclean : clean
	@$(RM) $(NAME)
	@echo "Name clean"
re: fclean $(NAME)

.PHONY: clean fclean re all
