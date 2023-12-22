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
WHITE='\033[0;37m'

.c.o:
	@$(CC) $(CFLAG) -c $< -o $(<:.c=.o)
all: fclean $(NAME) noel 

$(NAME) : $(OBJS)
	@$(CC) $(CFLAG) -o $(NAME) $(OBJS)
	@echo ${GREEN}">-Successful compilation-<"
clean:
	@clear
	@$(RM) $(OBJS)
	@echo ${BLUE}">------Files clean-------<\n"
fclean : clean
	@$(RM) $(NAME)
	@echo ${CYAN}">-------Name clean-------<\n"
re: fclean $(NAME)

.PHONY: clean fclean re all noel






red='\033[0;31m'
green='\033[0;32m'
orange='\033[0;33m'
blue='\033[0;34m'
purple='\033[0;35m'
cyan='\033[0;36m'
grey='\033[0;37m'
light_red='\033[1;31m'
light_green='\033[1;32m'
light_orange='\033[1;33m'
light_blue='\033[1;34m'
light_purple='\033[1;35m'
light_cyan='\033[1;36m'
white='\033[1;37m'
white_c='\033[6;37m'
red_c='\033[6;31m'
green_c='\033[6;32m'
orange_c='\033[6;33m'
blue_c='\033[6;34m'
purple_c='\033[6;35m'
cyan_c='\033[6;36m'



noel:
	@clear
	@echo $(white_c)"		 __  __					      _          _     _                       "
	@echo "		|  \/  | ____ _ __ _ __ _   _		     | |        (_)   | |                      "
	@echo "		| |\/| |/ __ \ '__| '__| | | | 		  ___| |__  _ __ _ ___| |_ _ __ ___   __ _ ___ "
	@echo "		| |  | |  ___/ |  | |  | |_| |		 / __| '_ \| '__| / __| __| '_ \` _ \ / _\` / __|"
	@echo "		|_|  |_|\____|_|  |_|  \___, |		| (__| | | | |  | \__ \ |_| | | | | | (_| \__ \\"
	@echo "		                        |___/		 \___|_| |_|_|  |_|___/\__|_| |_| |_|\__,_|___/	\n"
	@echo $(orange)"                                    .!,            .!,"
	@echo $(orange)"                                   ~ "$(light_orange)"6"$(orange)" ~          ~ "$(light_orange)"6"$(orange)" ~"
	@echo "                              "$(light_orange)".    '"$(white)" i"$(light_orange)" \`"$(light_orange)"  .-^-.   '"$(white)" i"$(light_orange)" \`"
	@echo "                           "$(light_orange)" _.|,_ "$(white)"  | |"$(light_orange)"  / .-. \  "$(white)" | |"
	@echo "                            "$(orange)"  |"$(white)"    .|_|."$(light_orange)"| (-, ) | "$(white)".|_|."
	@echo "                             "$(green)"/ \ "$(light_orange)"___)_(_|__'-'__|__)_(______"
	@echo "                            "$(green)"/"$(red)"\`,"$(green_c)"o"$(green)"\ "$(light_orange)")_______________________"$(white)"o"$(light_orange)"_("
	@echo $(green)"                           /_* "$(red)"~"$(green)"_\\\\"$(light_orange)"[___]___[___]___[___[_["$(white)"\\\`-."
	@echo $(green)"                           / "$(red_c)"o"$(red)" .'"$(green)"\\\\"$(light_orange)"[_]___[___]___[___]_[___"$(white)")\`-)"
	@echo $(green)"                          /_"$(red)",~'"$(green)" "$(blue)"*"$(green)"_\\\\"$(light_orange)"_]                 [_["$(red)"(  ("
	@echo $(green)"                          /"$(red)"\`."$(green)" "$(red)"*"$(green)"   \\\\"$(light_orange)"_]                 [___"$(red)"\ _\\"
	@echo $(green)"                         /   "$(red)"\`~. "$(cyan_c)"o"$(green)" \\\\"$(light_orange)"]      ;( ( ;     [_[_]"$(red)"\`-'"
	@echo $(green)"                        /_ *    "$(red)"\`~,"$(green)"_\\\\"$(light_orange)"    (( )( ;(;    [___]"
	@echo $(green)"                        /   "$(red_c)"o"$(green)"  "$(blue)"*"$(green)"  "$(red)"~'"$(green)"\\\\"$(grey)"   /\ /\ /\ /\   "$(light_orange)"[_[_]"
	@echo $(green)"                       / "$(orange)"*"$(green)"    "$(red)".~~'  "$(orange_c)"o"$(green)"\\\\"$(grey)"  ||_||_||_||   "$(light_orange)"[___]"
	@echo $(green)"                      /_"$(red)",.~~'\`"$(green)"    "$(red)"*"$(green)"  _\\\\"$(grey)"_||_||_||_||___"$(light_orange)"[_[_]_"
	@echo $(green)"                      /"$(red)"\`~..  "$(purple_c)"o"$(green)"        \\\\"$(red)":::::::::::::::::::::"$(white)"\\"
	@echo $(green)"                     / "$(purple)"*"$(green)"   "$(red)"\`'~.. "$(green)"  *   \\\\"$(red)":::::::::::::::::::::"$(white)"\\"
	@echo $(green)"                    /_     "$(cyan_c)"o"$(red)"    \`\`~~.,,"$(green)"_\\\\"$(white)"====================='"
	@echo $(green)"                    /  *      "$(blue)"*"$(green)"     "$(red)"..~'"$(green)"\\"
	@echo $(green)"                   /"$(red)"*"$(green)"    "$(orange_c)"o"$(red)"   _..~~\`'"$(cyan)"*   "$(blue_c)"o"$(green)"\\"
	@echo $(green)"                   \`-.__"$(red)".~'\`'"$(green)"   "$(orange)"*"$(green)"   ___.-'"
	@echo $(light_orange)"                         \":-------:\""
	@echo $(orange)"                           \_____/"