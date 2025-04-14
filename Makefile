# The name of the project
NAME = push_swap

VAL = valgrind
VALFLAGS = #--leak-check=full --show-leak-kinds=all

# Libft
LIBFT = ./libft/
LIBFT_LIB = $(LIBFT)libft.a

# A list of all .c files in the current directory
SRCS = push_swap.c algorithm.c stack_initialization.c nodes.c utils.c node_utils.c \
	moves.c push.c swap.c rotate.c reverse_rotate.c \
	handle_errors.c free_variables.c update_nodes.c \
	debug.c
# A list of all .o files that correspond to the .c files
OBJS_DIR = ./objs/
OBJS = $(SRCS:.c=.o)
HDERS = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -g3 #-Werror
ARFLAGS = -rc
RM = rm -f

COLOREND = \033[0m
GREEN = \033[1;32m
RED = \e[1;31m
YELLOW = \e[1;33m
BLUE = \033[0;34m
CIAN = \e[7;36m

# The default target - builds the project
all: $(NAME)

push:
	make
	./push_swap 99 0 25 -38 10 7 42

# A rule to build the project from the .o files
$(NAME): $(LIBFT_LIB) $(OBJS)
	@echo "$(CIAN)Compiling $(NAME)$(COLOREND)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) $(LIBFT_LIB)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT_LIB):
	@echo "$(CIAN)Compiling libft...$(BLUE)"
	make -C $(LIBFT) -f Makefile

# A rule to remove all .o files
clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) clean
	@echo "$(CIAN)Objects cleaned$(COLOREND)"

# A rule to remove all .o files and the project
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean
	@echo "$(CIAN)Full clean$(COLOREND)"

# A rule to rebuild everything from scratch
re: fclean all

# A rule to run the program
run: all
	./$(NAME) $(MAP)

norme:
	@echo "$(CIAN)SOURCES$(COLOREND)"
	@for file in $(SRCS); do \
		norminette $$file | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)$$file: OK!$(COLOREND)"; \
		else \
			echo "$(RED)"; \
			norminette $$file; \
			echo "$(COLOREND)"; \
		fi \
	done
	@echo "$(CIAN)\nHEADERS$(COLOREND)"
	@for header in $(HDERS); do \
		norminette $$header | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)$$header: OK!$(COLOREND)"; \
		else \
			echo "$(RED)"; \
			norminette $$header; \
			echo "$(COLOREND)"; \
		fi \
	done

# A special rule to tell make that these targets aren't files
.PHONY: all fclean re clean run error
