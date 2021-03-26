CC=gcc
CC_OPT= -g3 -fsanitize=address -Wall -Wextra -Werror
OUTPUT=my_ls

all: ${OUTPUT}

${OUTPUT}: main.o get_opt.o print_opt.o my.o
	${CC} ${CC_OPT} main.o get_opt.o print_opt.o my.o -o ${OUTPUT}

get_opt.o: get_opt.c
	${CC} ${CC_OPT} -c get_opt.c

print_opt.o: print_opt.c
	${CC} ${CC_OPT} -c print_opt.c

my.o: my.c
	${CC} ${CC_OPT} -c my.c

main.o: main.c
	${CC} ${CC_OPT} -c main.c

clean:
	rm *.o ${OUTPUT}