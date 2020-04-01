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

LIB_NAME	 = render.a

I_LIB_DIR	= include/

LIB_DIR	= src/

LIB_FILES	= move_sprite.c\
			  random.c\
			  drawing.c\
			  measure_distance.c\
			  sprite_creator.c\
			  sound_creator.c\
			  physics.c\
			  ui.c\
			  time.c\
			  text.c\
			  button_classic.c\
			  button_simple.c\
			  screen.c

CFLAGS	+= -I $(IDIR) -Wall -Wno-unused-parameter -Wextra -lm -lcsfml-graphics -lcsfml-system -lcsfml-audio

LIB		= $(addprefix $(LIB_DIR), $(LIB_FILES))

OBJS		 = $(LIB:.c=.o)

all: $(LIB_NAME) $(BIN_NAME)

$(LIB_NAME): $(OBJS)
	@ar rc $(LIB_NAME) $(OBJS)
	@echo -e "\033[1;32mRENDER libraries compilation complete !"

%.o : %.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@printf "${_CYAN}<Compiled>${_END} % 31s\n" $<

clean:
	@echo -e "\033[1;33mremoving RENDER compilation files !\033[1;36m"
	@rm -f $(OBJS)
	@rm -f $(LIB_NAME)

re:	clean all

.PHONY: all clean re
