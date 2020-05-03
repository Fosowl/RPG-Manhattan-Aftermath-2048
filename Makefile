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

# engine var

ENGINE_NAME		= starset.a
I_ENGINE_DIR	= engine/include/
ENGINE_DIR	= engine

# lib warlock var

LIB_NAME	 = warlock.a
LIB_I_DIR	= warlock/include/
LIB_DIR	= warlock/

# lib render var

RENDER_NAME		= render.a
RENDER_I_DIR	= lib_render/include
RENDER_DIR	=	lib_render/

# game var

BIN_NAME	= my_rpg
IDIR	= include/
SRC_DIR = src/

SRC_FILES	= 		main.c											\
					menu/init_menu.c								\
					menu/menu_loop.c								\
					menu/destroy_menu.c								\
					menu/init_struct.c								\
					menu/hover_display.c							\
					menu/how_to_play.c								\
					main_scene/control_direction.c					\
					main_scene/control.c							\
					main_scene/dog_set.c							\
					main_scene/girl_ai.c							\
					main_scene/introduction.c						\
					main_scene/load_ground.c						\
					main_scene/load_entities.c						\
					main_scene/load_scene.c							\
					main_scene/main_scene.c							\
					main_scene/object_sound.c						\
					main_scene/p_attack_anim.c						\
					main_scene/p_move_anim.c						\
					main_scene/pause.c								\
					main_scene/pick_object.c						\
					main_scene/player_attack.c						\
					main_scene/set_girl.c							\
					main_scene/set_player_anim.c					\
					main_scene/set_player_static.c					\
					main_scene/set_sound.c							\
					main_scene/set_zombie_anim.c					\
					main_scene/spawn_point.c						\
					main_scene/toggle_object.c						\
					main_scene/ui.c									\
					main_scene/update_object.c						\
					main_scene/weapon_strike.c						\
					main_scene/zombie_ai.c							\
					main_scene/zombie_loading.c						\
					map/read_map.c									\
					map/check_origin.c								\
					map/check_path.c								\
					inventory/create_button_all_inventory.c 		\
					inventory/create_case_element_inventory.c 		\
					inventory/create_element_inventory.c 			\
					inventory/destroy_inventory.c 					\
					inventory/malloc_inventory.c 					\
					inventory/event_inventory.c 					\
					inventory/object_inventory.c 					\
					inventory/check_object_inventory.c 				\
					inventory/update_nb_object.c 					\
					inventory/update_element.c 						\
					inventory/create_info_inventory.c 	 			\
					inventory/move_in_inventory.c 					\
					inventory/info_inventory.c 						\
					inventory/inventory_object_life.c 				\
# test var

TEST	 = tests/test.c

CFLAGS	+= -I $(IDIR) -I $(LIB_I_DIR) -I $(RENDER_I_DIR) -I $(I_ENGINE_DIR) -Wall -Wextra -lm
CFLAGS	+= -pedantic -fstack-protector-all
CFLAGS	+= -lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system -g3

SRC		= $(addprefix $(SRC_DIR), $(SRC_FILES))

LIB		= $(addprefix $(LIB_DIR), $(LIB_NAME))

RENDER	= $(addprefix $(RENDER_DIR), $(RENDER_NAME))

all: $(BIN_NAME)

$(BIN_NAME):
		@make fclean
		@cd $(LIB_DIR) ; make re
		@cd $(RENDER_DIR) ; make re
		@cd $(ENGINE_DIR) ; make
		@gcc -o $(BIN_NAME) $(SRC) $(LIB) $(RENDER) $(ENGINE_DIR)/$(ENGINE_NAME) $(CFLAGS)
		@printf "\e[1;32m<Linked> % 43s\n" $(SRC) | tr ' ' '.'
		@echo -e "${_END}${_BOLD}${_ICYAN}binary compilation complete !${_END}"

engine:
	@cd $(ENGINE_DIR) ; make clean ; make

debug:
	@gcc -o $(BIN_NAME) $(SRC) $(LIB) $(RENDER) $(ENGINE_DIR)/$(ENGINE_NAME) $(CFLAGS) -g3
	@printf "\e[1;32m<Linked> % 43s\n" $(SRC) | tr ' ' '.'
	@echo -e "${_END}${_BOLD}${_IYELLOW}\033[5mDEBUG MODE READY !\033[0m${_END}"


change:
		@cd $(RENDER_DIR) ; make
		@cd $(ENGINE_DIR) ; make
		@gcc -o $(BIN_NAME) $(SRC) $(LIB) $(RENDER) $(ENGINE_DIR)/$(ENGINE_NAME) $(CFLAGS)
		@printf "\e[1;32m<Linked> % 43s\n" $(SRC) | tr ' ' '.'
		@echo -e "${_END}${_BOLD}${_ICYAN}binary compilation complete !${_END}"

f:
	@gcc -o $(BIN_NAME) $(SRC) $(LIB) $(RENDER) $(ENGINE_DIR)/$(ENGINE_NAME) $(CFLAGS)
	@echo -e "${_END}${_BOLD}${_IYELLOW}\033[5mFAST COMPIL DONE !\033[0m${_END}"

sanitize:
	@gcc -o $(BIN_NAME) $(SRC) $(LIB) $(RENDER) $(ENGINE_DIR)/$(ENGINE_NAME) $(CFLAGS) -g3 -fsanitize=address
	@printf "\e[1;32m<Linked> % 43s\n" $(SRC) | tr ' ' '.'
	@echo -e "${_END}${_BOLD}${_IYELLOW}\033[5mADRESS SANITIZER MODE READY !\033[0m${_END}"

clean:
	@echo -e "${_BOLD}${_IRED}removing compilation files !${_END}"
	@cd $(LIB_DIR) ; make clean
	@cd $(RENDER_DIR) ; make clean
	@cd $(ENGINE_DIR) ; make clean
	@rm -f $(LIB_NAME)

tests_run: fclean all
	@make clean
	@gcc -o $(TEST_NAME) $(TEST) $(LIB) $(RENDER) $(ENGINE_DIR)/$(ENGINE_NAME) $(CFLAGS) --coverage -lcriterion
	@echo -e "${_BOLD}${_IGREEN}program test compiled !${_END}\n"
	./$(TEST_NAME)

fclean: clean
	@echo -e "${_BOLD}${_IRED}removing binary files !${_END}${_CYAN}"
	@rm -f $(BIN_NAME)

re:	fclean all

.PHONY: all clean fclean re
