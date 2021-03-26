CC=gcc
C_OPT= -g3 -fsanitize=address -Wall -Wextra -Werror
OUTPUT=my_ls

all: ${OUTPUT}

${OUTPUT}: main.o get_opt.o print_opt.o
	${CC} ${C_OPT} main.o get_opt.o print_opt.o -o ${OUTPUT}

get_opt.o: get_opt.c
	${CC} ${C_OPT} -c get_opt.c

print_opt.o: print_opt.c
	${CC} ${C_OPT} -c print_opt.c

main.o: main.c 
	${CC} ${C_OPT} -c main.c

clean:
	rm *.o ${OUTPUT}
