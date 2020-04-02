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

TEST_NAME	=	unit_tests

LIB_NAME	 = warlock.a

RENDER_NAME		= render.a

BIN_NAME	= name

LIB_I_DIR	= warlock/include/

RENDER_I_DIR	= lib_render/include

IDIR	= include/

LIB_DIR	= warlock/

RENDER_DIR	=	lib_render/

SRC_DIR = src/

SRC_FILES	= 		main.c										\
					dialog/malloc_dialog.c						\
					dialog/create_dialog.c						\
					dialog/event_dialog.c						\
					dialog/display_dialog.c						\
					game.c \
					manage_event.c \

TEST	 = tests/test.c

CFLAGS	+= -I $(IDIR) -I $(LIB_I_DIR) -Wall -Wextra -lm
CFLAGS	+= -lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system -g3

SRC		= $(addprefix $(SRC_DIR), $(SRC_FILES))

LIB		= $(addprefix $(LIB_DIR), $(LIB_NAME))

RENDER	= $(addprefix $(RENDER_DIR), $(RENDER_NAME))

all: $(BIN_NAME)

$(BIN_NAME):
		@cd $(LIB_DIR) ; make re
		@cd $(RENDER_DIR) ; make re
		@gcc -o $(BIN_NAME) $(SRC) $(LIB) $(RENDER) $(CFLAGS)
		@printf "\e[1;32m<Linked> % 43s\n" $(SRC) | tr ' ' '.'
		@echo -e "${_END}${_BOLD}${_ICYAN}binary compilation complete !${_END}"
		@make clean

debug:
	@gcc -o $(BIN_NAME) $(SRC) $(LIB) $(CFLAGS) -g3
	@printf "\e[1;32m<Linked> % 43s\n" $(SRC) | tr ' ' '.'
	@echo -e "${_END}${_BOLD}${_IYELLOW}\033[5mDEBUG MODE READY !\033[0m${_END}"
	@make clean

sanitize:
	@gcc -o $(BIN_NAME) $(SRC) $(LIB) $(CFLAGS) -g3 -fsanitize=address
	@printf "\e[1;32m<Linked> % 43s\n" $(SRC) | tr ' ' '.'
	@echo -e "${_END}${_BOLD}${_IYELLOW}\033[5mADRESS SANITIZER MODE READY !\033[0m${_END}"
	@make clean

clean:
	@echo -e "${_BOLD}${_IRED}removing compilation files !${_END}"
	@cd $(LIB_DIR) ; make clean
	@rm -f $(LIB_NAME)

tests_run: fclean all
	@gcc -o $(TEST_NAME) $(TEST) $(LIB) $(CFLAGS) --coverage -lcriterion
	@echo -e "${_BOLD}${_IGREEN}program test compiled !${_END}\n"
	./$(TEST_NAME)
	@make clean

fclean: clean
	@echo -e "${_BOLD}${_IRED}removing binary files !${_END}${_CYAN}"
	@rm -f $(BIN_NAME)

re:	fclean all

.PHONY: all clean fclean re
