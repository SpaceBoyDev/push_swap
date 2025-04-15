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

ARG = -602 235 104 418 958 -356 -59 -168 -263 722 645 -111 640 281 209 -759 -16 -633 -987 -62 109 -879 -873 -302 -517 -191 122 -954 -936 -829 592 -353 245 377 798 557 -785 -363 689 -842 -233 -504 -605 328 858 409 -632 6 -819 406 -863 -426 -638 -158 -650 -71 298 292 164 354 523 -497 591 432 -73 131 -130 -279 10 -707 -893 -990 -903 -911 -474 -86 -372 206 -221 255 121 -277 519 67 -141 -500 -216 -541 -185 -687 27 -495 -9 461 -977 499 -956 772 -754 370 -156 -700 -938 -988 32 -840 -357 -850 230 807 417 742 -746 897 -482 315 861 -984 -640 -342 -870 -597 942 8 191 329 -789 43 892 -670 408 -796 -547 275 136 776 50 822 -398 845 829 620 407 -777 -871 623 111 60 -894 842 175 -32 -892 162 -179 732 301 -900 556 -220 -969 -671 -899 920 -795 65 -980 912 518 -793 -730 929 -132 340 238 -444 -140 339 -748 -80 72 89 326 952 -885 641 -349 -43 846 -515 564 420 -332 -712 511 -524 2 -502 250 994 -751 -451 -365 -972 -57 -378 -8 -947 -960 510 311 -814 282 81 707 728 -576 -160 -384 -692 107 -964 -652 -207 48 915 154 768 -246 -933 -493 -402 -341 -663 383 -926 396 966 -208 -825 500 -982 694 -718 -767 672 -830 810 -535 -409 520 -214 -330 374 871 836 -726 -828 -580 -844 778 -101 -193 352 169 919 -485 695 -618 708 -427 -40 11 231 23 393 445 -338 -322 601 706 -318 342 30 878 -713 -587 -925 -562 -98 -146 -18 85 873 786 -729 93 402 -983 -780 -434 875 934 638 438 998 -637 -314 -620 770 525 211 -283 -148 -91 -219 368 671 171 859 327 746 -683 855 302 767 305 228 112 820 87 -492 337 -609 560 697 -222 989 -308 35 -479 909 36 -1 498 514 753 646 442 865 663 -807 190 -431 -435 288 -823 -231 252 -521 487 -367 -993 -724 876 22 70 224 608 -100 -447 20 -35 849 -708 257 431 152 182 787 -567 436 412 675 639 369 -265 -989 -476 -262 -293 553 360 -470 -52 -395 703 14 -757 -61 545 366 -313 78 -373 -812 -877 852 490 479 -592 210 808 193 268 350 -78 -974 -851 -138 -530 202 -601 995 777 -867 795 -377 918 284 -669 729 -173 740 -374 -271 158 617 -706 -902 -439 688 310 -438 -568 -321 -661 88 201 -691 361 184 451 775 269 916 -421 -213 734 879 392 -847 635 754 726 444 825 -292 -37 -776 -923 367 -737 -400 996 895 127 891 270 -623 938 644 115 -28 -255 582 594 313 605 780 681 940 -442 922 -121 -755 735 -253 -153 969

# The default target - builds the project
all: $(NAME)

push:
	make
	./push_swap "ARG" | wc -l

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
