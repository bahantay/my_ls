NAME	=	my_ls

SRC	=	src/main.c		\
		src/simple_ls.c		\
		src/check_flag.c	\
		src/can_open_dir.c	\
		src/flags.c		\
		src/flag_t.c		\
		src/flag_l.c		\
		src/display_l.c		\
		src/flag_r.c		\
		src/count_files.c	\
		src/fill_tab.c		\
		src/time_check.c	\
		src/swap_elems.c	\
		src/my_putchar.c	\
		src/my_putstr.c		\
		src/my_strlen.c		\
		src/my_put_nbr.c	\
		src/my_strcat.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wextra -Wall -g3 -fsanitize=address

CPPFLAGS=	-I./include

all	:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(SRC) $(CPPFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
