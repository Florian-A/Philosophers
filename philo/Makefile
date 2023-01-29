# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: f██████ <f██████>                          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 12:33:02 by f██████           #+#    #+#              #
#    Updated: 2023/01/29 15:36:47 by f██████          ###   ########.fr        #
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

# main
OBJS_PS = $(SRCS_PS:.c=.o)
SRCS_PS = $(addprefix $(SRC_DIR)/, \
main.c exit.c philo_action.c doctor_action.c routine.c \
philo_accessor1.c philo_accessor2.c cave_accessor.c msg.c \
)

# philosopher tool
OBJS_PST = $(SRCS_PST:.c=.o)
SRCS_PST = $(addprefix $(SRC_DIR)/, \
philo.c cave.c time.c \
)

# utest
OBJS_UTEST = $(UTEST_SRC:.c=.o)
UTEST_SRC = $(addprefix ./.utests/, \
main.c error.c test_create_philo.c test_get_left_philo.c \
test_ms_betwen.c test_ms_from_last_eat.c test_ms_from_start.c \
test_ms_sleep.c \
)

# main tool
OBJS_MT = $(SRC_MT:.c=.o)
SRC_MT = $(addprefix $(SRC_DIR)/tools/, \
ft_atoi.c ft_calloc.c ft_isdigit.c ft_memset.c \
ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c \
ft_lstfirst.c ft_lstlast.c ft_lstnew.c ft_lst_push.c \
)

SRC_DIR	= ./sources
INC_DIR	= ./includes/
CC = cc
MF = Makefile

ifeq ($(DEBUG), 1)
FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
else ifeq ($(DEBUG), 2)
FLAGS = -Wall -Wextra -Werror -fsanitize=thread -g
else
FLAGS = -Wall -Wextra -Werror -O3
endif

LIBTEST_PATH = ./libtest/libtest.a
NAME = philo
PS_HEADER_FILE = $(INC_DIR)/philosophers.h
UTEST_NAME = utest
UTEST_HEADER_FILE = $(INC_DIR)/utest.h

all : $(NAME) test

$(NAME) : $(OBJS_MT) $(OBJS_PS) $(OBJS_PST)
	@$(CC) $(FLAGS) $(OBJS_MT) $(OBJS_PS) $(OBJS_PST) -o $(NAME)
	@echo "\n${GREEN}> Compilation of philosophers is success 🎉${END}"

./.utests/%.o : ./.utests/%.c $(UTEST_HEADER_FILE) $(MF)
	@/bin/echo -n .
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR) 

%.o : %.c $(PS_HEADER_FILE) $(MF)
	@/bin/echo -n .
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)

clean :
	@rm -f $(OBJS_MT)
	@rm -f $(OBJS_PS)
	@rm -f $(OBJS_PST)
	@rm -f $(OBJS_UTEST)
	@make clean -C ./libtest
	@echo "${YELLOW}> All objects files of philosophers have been deleted ❌${END}"

fclean : clean
	@rm -f $(NAME)
	@rm -f $(UTEST_NAME)
	@make fclean -C ./libtest
	@echo "${YELLOW}> Cleaning of philosophers has been done ❌${END}"

re : fclean
	@make all

_test :
	@make -C ./libtest DEBUG=$(DEBUG)

test: _test
	@make $(UTEST_NAME)

$(UTEST_NAME) : $(MF) $(OBJS_MT) $(OBJS_PST) $(OBJS_UTEST) $(LIBTEST_PATH)
	@$(CC) $(FLAGS) $(OBJS_MT) $(OBJS_PST) $(OBJS_UTEST) $(LIBTEST_PATH) -o $(UTEST_NAME)
	@echo "\n${GREEN}> Compilation of unit tests is success 🎉${END}"

.PHONY:	all clean fclean re test