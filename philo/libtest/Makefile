# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: f██████ <f██████>                          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 11:45:53 by f██████           #+#    #+#              #
#    Updated: 2023/01/29 15:36:58 by f██████          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# minimal color codes
END=$'\x1b[0m
BOLD=$'\x1b[1m
UNDER=$'\x1b[4m
REV=$'\x1b[7m
GREY=$'\x1b[30m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m

# test
OBJS_TEST = $(SRC_TEST:.c=.o)
SRC_TEST = $(addprefix $(SRC_DIR)/test/, \
utest.c test_show_start.c test_show_result.c test_init_struct.c  \
)

SRC_DIR	= .
INC_DIR	= ./includes/
CC = cc
AR = ar
MF = Makefile

ifeq ($(DEBUG), 1)
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
else ifeq ($(DEBUG), 2)
FLAGS = -Wall -Wextra -Werror -fsanitize=thread -g
else
FLAGS = -Wall -Wextra -Werror
endif

LIBTEST_NAME = libtest.a
LIBTEST_HEADER_FILE	= $(INC_DIR)/libtest.h

all : $(LIBTEST_NAME)

$(LIBTEST_NAME) : $(MF) $(OBJS_TEST)
	@$(AR) -rcs $(LIBTEST_NAME) $(OBJS_TEST)
	@echo "\n${GREEN}> Compilation of the libtest is success 🎉${END}"

clean :
	@rm -f $(OBJS_TEST)
	@echo "${YELLOW}> All objects files of libtest have been deleted ❌${END}"

fclean : clean
	@rm -f $(LIBTEST_NAME)
	@echo "${YELLOW}> Cleaning of libtest has been done ❌${END}"

re :fclean
	@make all

./test/%.o : ./test/%.c $(LIBTEST_HEADER_FILE) Makefile
	@/bin/echo -n .
	@$(CC) $(FLAGS) -c $< -o $@  -I $(INC_DIR) 

.PHONY: all clean fclean re