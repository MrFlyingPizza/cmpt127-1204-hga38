all: t1 t2

t1: t1.c demo.c
	gcc -Wall -Wextra -o t1 demo.c t1.c

t2: t2.c demo.c
	gcc -Wall -Wextra -o t2 demo.c t2.c

clean:
	rm -f demo t1 t2 *.o