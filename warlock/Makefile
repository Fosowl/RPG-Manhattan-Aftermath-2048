##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

# color codes
_END=$'\x1b[0m'
_BOLD=$'\x1b[1m'
_UNDER=$'\x1b[4m'
_REV=$'\x1b[7m'

# Colors
_GREY=$'\x1b[30m'
_RED=$'\x1b[31m'
_GREEN=$'\x1b[32m'
_YELLOW=$'\x1b[33m'
_BLUE=$'\x1b[34m'
_PURPLE=$'\x1b[35m'
_CYAN=$'\x1b[36m'
_WHITE=$'\x1b[37m'

# Inverted, i.e. colored backgrounds
_IGREY=$'\x1b[40m'
_IRED=$'\x1b[41m'
_IGREEN=$'\x1b[42m'
_IYELLOW=$'\x1b[43m'
_IBLUE=$'\x1b[44m'
_IPURPLE=$'\x1b[45m'
_ICYAN=$'\x1b[46m'
_IWHITE=$'\x1b[47m'

CC=gcc

TEST_NAME	=	unit_tests

LIB_NAME	 = warlock.a

IDIR	= include/

LIB_DIR	= src/

LIB_FILES	= gather/count.c\
			  gather/get.c\
			  gather/get_next_line.c\
			  gather/letter_info.c\
			  gather/buffer_info.c\
			  number/base.c\
			  number/convertion.c\
			  number/sort.c\
			  output/converter.c\
			  output/call_function.c\
			  output/error.c\
			  output/handle_case.c\
			  output/my_printf.c\
			  output/my_putchar.c\
			  output/my_putnbr.c\
			  output/my_putstr.c\
			  output/print_float.c\
			  parsing/cut.c\
			  parsing/letter.c\
			  parsing/light_python.c\
			  parsing/parsing.c\
			  parsing/replace.c\
			  string/initialize.c\
			  string/initialize_more.c\
			  string/array.c\
			  string/copy.c\
			  arg_parser/arg_parser.c\
			  core/debug.c\
			  core/emulate_go_if.c

TEST_1	 = tests/gather_test.c\
		   tests/gather_test_2.c

TEST_2	 = tests/number_test.c

TEST_3	 = tests/output_test.c\
		   tests/output_test_2.c

TEST_4	 = tests/parsing_test.c\
		   tests/parsing_test_2.c\
		   tests/parsing_test_3.c

TEST_5	= tests/string_test.c

CFLAGS	+= -I $(IDIR) -Wall -Wextra -lm

LIB		= $(addprefix $(LIB_DIR), $(LIB_FILES))

OBJS		 = $(LIB:.c=.o)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	@ar rc $(LIB_NAME) $(OBJS)
	@echo -e "${_BOLD}${_ICYAN}libraries compilation complete !${_END}${_WHITE}"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "${_CYAN}<Compiled>${_END} % 31s\n" $<

clean:
	@echo -e "${_BOLD}${_IRED}removing compilation files !${_END}"
	@rm -f $(OBJS) *.gcda *.gcno
	@rm -f $(LIB_NAME)

tests: fclean all
	@gcc -o $(TEST_NAME) $(TEST_1) $(LIB_NAME) $(CFLAGS) --coverage -lcriterion
	@echo -e "${_BOLD}${_IGREEN}gather test compiled !${_END}\n"
	./$(TEST_NAME)
	@rm $(TEST_NAME)
	@echo -e "${_BOLD}${_WHITE}gather test function...[${_GREEN}OK${_END}] !${_END}\n"
	@gcc -o $(TEST_NAME) $(TEST_2) $(LIB_NAME) $(CFLAGS) --coverage -lcriterion
	@echo -e "${_BOLD}${_IGREEN}number test compiled !${_END}"
	@./$(TEST_NAME)
	@rm $(TEST_NAME)
	@echo -e "${_BOLD}${_WHITE}number test function...[${_GREEN}OK${_END}] !${_END}\n"
	@gcc -o $(TEST_NAME) $(TEST_3) $(LIB_NAME) $(CFLAGS) --coverage -lcriterion
	@echo -e "${_BOLD}${_IGREEN}output test compiled ! !${_END}"
	@./$(TEST_NAME)
	@rm $(TEST_NAME)
	@echo -e "${_BOLD}${_WHITE}output test function...[${_GREEN}OK${_END}] !${_END}\n"
	@gcc -o $(TEST_NAME) $(TEST_4) $(LIB_NAME) $(CFLAGS) --coverage -lcriterion
	@echo -e "${_BOLD}${_IGREEN}parsing compiled !${_END}"
	@./$(TEST_NAME)
	@rm $(TEST_NAME)
	@echo -e "${_BOLD}${_WHITE}parsing test function...[${_GREEN}OK${_END}] !${_END}\n"
	@gcc -o $(TEST_NAME) $(TEST_5) $(LIB_NAME) $(CFLAGS) --coverage -lcriterion
	@echo -e "${_BOLD}${_IGREEN}string compiled !${_END}"
	@./$(TEST_NAME)
	@rm $(TEST_NAME)
	@echo -e "${_BOLD}${_WHITE}string test function...[${_GREEN}OK${_END}] !${_END}\n"
	@make clean

import:
	@echo -e "${_BOLD}${_PURPLE}cloning libraries !${_END}"
	git clone https://github.com/Fosowl/warlock-C-libraries.git
	@echo -e "${_BOLD}${_YELLOW}copy include !${_END}"
	@cp -r ./warlock-C-libraries/include/ ./include
	@echo -e "${_BOLD}${_YELLOW}copy warlock lib !${_END}"
	@cp -r ./warlock-C-libraries/warlock ./warlock
	@echo -e "${_BOLD}${_YELLOW}copy source!${_END}"
	@cp -r ./warlock-C-libraries/src ./src
	@echo -e "${_BOLD}${_PURPLE}remove libraries folder !${_END}"
	@rm -rf ./warlock-C-libraries

re:	fclean all

.PHONY: all clean fclean re
