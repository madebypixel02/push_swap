# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/29 10:50:06 by aperez-b          #+#    #+#              #
#    Updated: 2021/09/27 20:25:24 by aperez-b         ###   ########.fr        #
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

UNAME = $(shell uname -s)

# Properties for MacOS
ECHO = echo
CDEBUG = #-g3 -fsanitize=address
CHECKER = tests/checker_Mac
ifeq ($(UNAME), Linux)
	#Properties for Linux
	ECHO = echo -e
	LEAKS = valgrind --leak-check=full --show-leak-kinds=all -s -q 
	CHECKER = tests/checker_linux
endif

# Make variables
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc -MD
SRC_DIR = src
SRCB_DIR = srcb
OBJ_DIR = obj
OBJB_DIR = objb
BIN_DIR = bin
BIN = push_swap
NAME = $(BIN_DIR)/$(BIN)
LIBFT = libft/bin/libft.a


SRC = stack.c stack_utils.c stack_transform.c stack_multi.c	\
	  order.c order_utils.c stack_print.c main.c

SRCB = 

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJB = $(addprefix $(OBJB_DIR)/, $(SRCB:.c=.o))

# push_swap test variables
N = 0
N_VALID = $(shell [ $(N) -gt 0 ] && echo True)

ifeq ($(N_VALID), True)
	ARGS := $(shell seq -$(N) $(N) | sort -R | head -n $(N) | tr '\n' ' ')
endif

all: $(NAME)

$(NAME): create_dirs compile_libft $(OBJ)
	@$(CC) $(CFLAGS) $(CDEBUG) $(OBJ) $(LIBFT) -o $@
	@$(ECHO) "$(GREEN)$(BIN) is up to date!$(DEFAULT)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(ECHO) "Compiling $(BLUE)$<$(DEFAULT)..."
	@$(CC) $(CFLAGS) $(CDEBUG) -c $< -o $@

bonus: all
	@$(ECHO) "$(MAGENTA)Bonus Compilation Complete in $(BIN)!$(DEFAULT)"

compile_libft:
	@make all -C libft/

test: all
	@if [ $(N) -le 0 ]; then \
		$(ECHO) "Error"; \
	else \
		$(ECHO) "$(YELLOW)Performing test with custom parameters...$(DEFAULT)\n"; \
		$(ECHO) "Command: $(GRAY)$(LEAKS)./$(NAME) $(ARGS)$(DEFAULT)\n"; \
		$(LEAKS)./$(NAME) $(ARGS) > .out.tmp; \
		cat .out.tmp; \
		printf "\nMoves: "; \
	   	cat .out.tmp | wc -l | tr -d " "; \
		printf "Checker: "; \
	   	cat .out.tmp | ./$(CHECKER) $(ARGS); \
		$(RM) .out.tmp; \
	fi

create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJB_DIR)
	@mkdir -p $(BIN_DIR)

clean:
	@$(ECHO) "$(BLUE)Cleaning up object files in $(NAME)...$(DEFAULT)"
	@make clean -C libft
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(OBJB_DIR)

fclean: clean
	@$(RM) -r $(BIN_DIR)
	@$(RM) $(LIBFT)
	@$(ECHO) "$(CYAN)Removed $(NAME)$(DEFAULT)"
	@$(ECHO) "$(CYAN)Removed $(LIBFT)$(DEFAULT)"

norminette:
	@$(ECHO) "$(CYAN)\nChecking norm for $(BIN)...$(DEFAULT)"
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) $(SRCB_DIR) inc/
	@make norminette -C libft/

re: fclean all
	@$(ECHO) "$(YELLOW)Cleaned and Rebuilt Everything for $(NAME)!$(DEFAULT)"

git:
	git add .
	git commit
	git push

-include $(OBJ_DIR)/*.d
-include $(OBJB_DIR)/*.d

.PHONY: all clean fclean bonus compile_libft norminette test git create_dirs re
