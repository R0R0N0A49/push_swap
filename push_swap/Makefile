NAME=push_swap
CC=cc
CFLAG= -Werror -Wall -Wextra -g
SRCS= display.c ft_push.c ft_rotate.c ft_split_int.c ft_swap.c push_swap.c push_swap_utils.c push_swap_utils_2.c security.c\
	ft_printf/ft_printf.c ft_printf/ft_printf_utils.c test.c
OBJS=$(SRCS:.c=.o)
RM=rm -f

CYAN='\033[1;36m'
BLUE='\033[1;34m'
GREEN='\033[6;32m'

.c.o:
	@$(CC) $(CFLAG) -c $< -o $(<:.c=.o)
all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAG) -o $(NAME) $(OBJS)
	@echo ${GREEN}"--Successful compilation--"
clean:
	@clear
	@$(RM) $(OBJS)
	@echo ${BLUE}"-------Files clean--------\n"
fclean : clean
	@$(RM) $(NAME)
	@echo ${CYAN}"--------Name clean--------\n"
re: fclean $(NAME)

.PHONY: clean fclean re all
