NAME=push_swap
CC=cc
CFLAG= -Werror -Wall -Wextra
SRCS= ft_push.c ft_rotate.c ft_split.c ft_swap.c push_swap.c push_swap_utils.c push_swap_utils_2.c security.c\
	ft_printf/ft_printf.c ft_printf/ft_printf_utils.c 
OBJS=$(SRCS:.c=.o)
RM=rm -f

CYAN='\033[1;36m'
BLUE='\033[1;34m'
GREEN='\033[6;32m'

all: $(NAME)
$(NAME): $(OBJS)
	@$(CC) ${CFLAG} $(OBJS) -o $(NAME) 
	@echo ${GREEN}"##Successful compilation##"
.c: .o
	@$(CC) $(CFLAG) -c $< -o $(<:.c=.o)
clean:
	@clear
	@$(RM) $(OBJS)
	@echo ${BLUE}"#######Files clean########\n"
fclean : clean
	@$(RM) $(NAME)
	@echo ${CYAN}"########Name clean########\n"
re: fclean $(NAME)

.PHONY: clean fclean re all
