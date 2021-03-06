# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartino <amartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/26 11:56:39 by amartino          #+#    #+#              #
#    Updated: 2020/02/12 17:06:14 by amartino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
                     ####################################
                     #                   				#
                     #       	MAIN VARIABLES 			#
                     #                   				#
                     ####################################
NAME_PUSH_SWP = push_swap
NAME_CHECKER = checker
LIB_DIR = ./libft/ft_printf
LIB = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DFLAGS =  -Wall -Wextra -Werror -fsanitize=address,undefined -g3
INCLUDES += -I./include
INCLUDES += -I./libft/includes
INCLUDES += -I./libft/ft_printf/includes
HEAD += ./include/define_ps.h
HEAD += ./include/push_swap.h

                     ####################################
                     #                   				#
                     #       		PATHS     			#
                     #                   				#
                     ####################################
# LIB
LIB_PATH = $(LIB_DIR)/$(LIB)

# SRCS
PATH_SRC += 0_push_swp/
PATH_SRC += 1_checker/
PATH_SRC += 2_init/
PATH_SRC += 3_tool/
PATH_SRC += 4_clean/
PATH_SRC += 5_bonus/

vpath %.c $(PATH_SRC)

                     ####################################
                     #                   				#
                     #       	   SOURCE      			#
                     #                   				#
                     ####################################
# main
MAIN_PUSH = main_pushswap
MAIN_CHECK = main_check

# push_swap
SRCS += push_swp
SRCS += operation_on_stack
SRCS += sublist_tools
SRCS += perfect_sort
SRCS += perfect_sort_bis

# checker
SRCS += checker

# initialize
SRCS += init
SRCS += parse

# tool
SRCS += push_stack
SRCS += swap_stack
SRCS += swap_both
SRCS += shift_stack
SRCS += rotate_both
SRCS += rotate_stack
SRCS += reverse_rotate_stack
SRCS += is_it_sorted

# clean
SRCS += clean

#bonus
SRCS += print
SRCS += color
SRCS += output_file
SRCS += bonus_tools

                     ####################################
                     #                   				#
                     #       	  VARIABLES    			#
                     #                   				#
                     ####################################
nb ?= 50
T ?= sample
VAL ?= no
REQUEST = 'read -p "Enter a commit message:" pwd; echo $$pwd'
COMMIT_MESSAGE ?= $(shell bash -c $(REQUEST))
ARG= ARG=`ruby -e "puts (0..$(nb) - 1).to_a.shuffle.join(' ')"`

                     ####################################
                     #                   				#
                     #              OBJS	   			#
                     #                   				#
                     ####################################
BUILD_DIR = build/

MAIN_OBJ_PS = $(patsubst %, %.o, $(MAIN_PUSH))
MAIN_OBJ_C = $(patsubst %, %.o, $(MAIN_CHECK))
OBJS = $(patsubst %, $(BUILD_DIR)%.o, $(SRCS))

                     ####################################
                     #                   				#
                     #       	   RULES      			#
                     #                   				#
                     ####################################
all: $(NAME_CHECKER) $(NAME_PUSH_SWP)
	echo "\n$(CYAN)MAKE COMPLETE$(END)"

$(NAME_PUSH_SWP): $(BUILD_DIR) $(MAIN_OBJ_PS) $(OBJS) $(LIB_PATH)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ_PS) $(OBJS) $(LIB_PATH) $(INCLUDES)

$(NAME_CHECKER): $(BUILD_DIR) $(MAIN_OBJ_C) $(OBJS) $(LIB_PATH)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ_C) $(OBJS) $(LIB_PATH) $(INCLUDES)

$(BUILD_DIR):
	mkdir $@

$(MAIN_OBJ_PS): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	echo "$(CFLAGS) \t\t $(GREEN)$<$(END)"

$(MAIN_OBJ_C): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	echo "$(CFLAGS) \t\t $(GREEN)$<$(END)"

$(OBJS): $(BUILD_DIR)%.o: %.c $(HEAD) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	echo "$(CFLAGS) \t\t $(GREEN)$<$(END)"

$(LIB_PATH): FORCE
	make -C $(LIB_DIR)

unit_test:
	@echo "\n"
	@# $(ARG) ; ./$(NAME_PUSH_SWP) $$ARG
	$(ARG) ; ./$(NAME_PUSH_SWP) $$ARG | ./$(NAME_CHECKER) $$ARG

run: all
	$(MAKE) unit_test
	echo "\n$(MAGENTA)result:$(END)"
	ls -t result

clean:
	$(RM) $(OBJS)
	$(RM) -R ./$(BUILD_DIR)
	$(RM) -R $(MAIN_PUSH).o $(MAIN_CHECK).o
	echo "$(YELLOW)OBJS$(END) \t\t were \t\t $(GREEN)clean$(END)\n"
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	$(RM) -R $(NAME_PUSH_SWP) $(NAME_CHECKER) $(MAIN_PUSH).o $(MAIN_CHECK).o
	echo "$(YELLOW)$(NAME_PUSH_SWP)$(END) and $(YELLOW)$(NAME_CHECKER)$(END) \t were \t $(GREEN)clean$(END)\n"
	$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

.PHONY: clean fclean all re t FORCE git
.SILENT: $(NAME) $(OBJS) $(BUILD_DIR) $(MAIN_OBJ_PS) $(MAIN_OBJ_C) all re t \
		$(LIB_PATH) $(NAME_PUSH_SWP) $(NAME_CHECKER) clean fclean run \
		all
FORCE:


                     ####################################
                     #                   				#
                     #       	  	IFEQ	   			#
                     #                   				#
                     ####################################

# FLAGS
ifeq ($(f), no)
CFLAGS = -g
else ifeq ($(f), f)
CFLAGS = $(DFLAGS)
endif

# VALGRIND
$(VAL):
ifeq ($(VAL), no)
VALGRIND =
else
CFLAGS += -g
SHOW_LEAK = --show-leak-kinds=definite
VALGRIND = valgrind --track-origins=yes --leak-check=full $(SHOW_LEAK)
endif

                     ####################################
                     #                   				#
                     #        		GIT       			#
                     #                   				#
                     ####################################
git:
	@git add -f -A
	@git commit -m "$(COMMIT_MESSAGE)"
	@git push

                     ####################################
                     #                   				#
                     #       		COLOR     			#
                     #                  				#
                     ####################################
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
MAGENTA = \x1b[35m
CYAN = \x1b[36m
END = \x1b[0m
