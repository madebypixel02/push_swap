# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/29 10:50:06 by aperez-b          #+#    #+#              #
#    Updated: 2023/04/08 14:38:46 by aperez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SHELL=/bin/bash
UNAME = $(shell uname -s)

# Properties for MacOS
CDEBUG = #-g3 -fsanitize=address
CHECKER = tests/checker_Mac
ifeq ($(UNAME), Linux)
	#Properties for Linux
	LEAKS = valgrind --leak-check=full --show-leak-kinds=all -s -q 
	CHECKER = tests/checker_linux
endif

# Make variables
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc -MD
AR = ar rcs
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
BIN = push_swap
NAME = $(BIN_DIR)/$(BIN)
PRINTF = printf
LIBFT = libft/bin/libft.a
LIBFT_DIR = libft
LIBFT_SRC = $(shell [ -d libft ] && ls libft/src*/*.c)

SRC = stack.c stack_utils.c stack_transform.c stack_multi.c	\
	  order.c order_utils.c stack_print.c main.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# push_swap test variables
N = 0
N_VALID = $(shell [ $(N) -gt 0 ] && echo True)

ifeq ($(N_VALID), True)
	ARGS := $(shell seq -$(N) $(N) | sort -R | head -n $(N) | tr '\n' ' ')
endif

# Progress vars
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) | $(BIN_DIR)
	@$(CC) $(CFLAGS) $(CDEBUG) $(OBJ) $(LIBFT) -o $@
	@$(PRINTF) "\r%100s\r$(GREEN)$(BIN) is up to date!$(DEFAULT)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) $(CDEBUG) -c $< -o $@

$(LIBFT): $(LIBFT_SRC) | $(LIBFT_DIR) $(BIN_DIR)
	@make all -C libft
	@$(AR) $(NAME) $(LIBFT)

test: all
	@if [ $(N) -le 0 ]; then \
		$(PRINTF) "Error\n"; \
	else \
		$(PRINTF) "$(YELLOW)Performing test with custom parameters...$(DEFAULT)\n\n"; \
		$(PRINTF) "Command: $(GRAY)$(LEAKS)./$(NAME) $(ARGS)$(DEFAULT)\n\n"; \
		$(LEAKS)./$(NAME) $(ARGS) > .out.tmp; \
		cat .out.tmp; \
		printf "\nMoves: "; \
	   	cat .out.tmp | wc -l | tr -d " "; \
		printf "Checker: "; \
	   	cat .out.tmp | ./$(CHECKER) $(ARGS); \
		$(RM) .out.tmp; \
	fi

clean: | $(LIBFT_DIR)
	@$(PRINTF) "$(CYAN)Cleaning up object files in $(NAME)...$(DEFAULT)\n"
	@make clean -C libft
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) -r $(BIN_DIR)
	$(RM) $(LIBFT)
	@$(PRINTF) "$(CYAN)Removed $(LIBFT)$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

norminette: | $(LIBFT_DIR)
	@$(PRINTF) "$(CYAN)\nChecking norm for $(BIN)...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) $(INC_DIR)
	@make norminette -C libft

$(LIBFT_DIR):
	@git clone https://gitlab.com/madebypixel02/libft.git

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJB_DIR):
	@mkdir -p $(OBJB_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

re: fclean
	@make all

git:
	git add .
	git commit
	git push

-include $(OBJ_DIR)/*.d
-include $(OBJB_DIR)/*.d

.PHONY: all clean fclean norminette test git re
