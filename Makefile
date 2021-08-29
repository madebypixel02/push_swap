# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/29 10:50:06 by aperez-b          #+#    #+#              #
#    Updated: 2021/08/29 14:41:21 by aperez-b         ###   ########.fr        #
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
ifeq ($(UNAME), Linux)
	#Properties for Linux
	ECHO = echo -e
	LEAKS = valgrind --leak-check=full --show-leak-kinds=all -s -q 
	CDEBUG =
endif

# Make variables
CFLAGS = #-Wall -Wextra -Werror
RM = rm -f
CC = gcc
DIR_M = mandatory
DIR_B = bonus
DIR_OBJ = lib
LIBFT = libft/libft.a
NAME = push_swap
INC = #-I libft/lib/
LIB = #-L libft/

SOURCE_M = stack.c

SOURCE_B = 

SRC_M = $(addprefix $(DIR_M)/, $(SOURCE_M)) tests/main.c

SRC_B = $(addprefix $(DIR_B)/, $(SOURCE_B))

OBJ_M = $(addprefix $(DIR_OBJ)/, $(SOURCE_M:.c=.o)) lib/main.o

OBJ_B = $(addprefix $(DIR_OBJ)/, $(SOURCE_B:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_M) compile_libft
	@$(CC) $(CFLAGS) $(CDEBUG) $(OBJ_M) $(LIBFT) -o $@

$(OBJ_M): $(SRC_M)
	@$(ECHO) "$(RED)Mandatory objects outdated in $(NAME)! Compiling again...$(DEFAULT)"
	@$(CC) $(CFLAGS) $(CDEBUG) -c $^
	@mv -f $(SOURCE_M:.c=.o) main.o $(DIR_OBJ)
	@$(ECHO) "$(GREEN)Mandatory Compilation Complete in $(NAME)!$(DEFAULT)"

bonus: $(OBJ_B)

$(OBJ_B): $(SRC_B)
	@$(ECHO) "$(RED)Bonus objects outdated in $(NAME)! Compiling again...$(DEFAULT)"
	@$(CC) $(CFLAGS) $(CDEBUG) -c $^
	@mv -f $(SOURCE_B:.c=.o) $(DIR_OBJ)
	@$(ECHO) "$(MAGENTA)Bonus Compilation Complete in $(NAME)!$(DEFAULT)"

compile_libft:
	@make all -C libft/

test: all
	@$(ECHO) "$(YELLOW)Performing test with custom main...$(DEFAULT)"
	@$(ECHO)
	@$(ECHO) "Command: $(GRAY)$(LEAKS)./$(NAME)$(DEFAULT)"
	@$(ECHO)
	@$(LEAKS)./$(NAME)

clean:
	@$(ECHO) "$(BLUE)Cleaning up object files in $(NAME)...$(DEFAULT)"
	@make clean -C libft
	@$(RM) $(OBJ_M) $(OBJ_B)

fclean: clean
	@$(RM) $(LIBFT)
	@$(RM) libft/$(LIBFT)
	@$(RM) $(NAME)
	@$(ECHO) "$(CYAN)Removed $(NAME)$(DEFAULT)"
	@$(ECHO) "$(CYAN)Removed $(LIBFT)$(DEFAULT)"

norminette:
	@$(ECHO) "$(CYAN)\nChecking norm for $(NAME)...$(DEFAULT)"
	@norminette -R CheckForbiddenSourceHeader $(SRC_M) $(SRC_B) lib/
	@make norminette -C libft/

re: fclean all
	@$(ECHO) "$(YELLOW)Cleaned and Rebuilt Everything for $(NAME)!$(DEFAULT)"

git:
	git add .
	git commit
	git push

.PHONY: all clean fclean bonus compile_libft norminette test git re
