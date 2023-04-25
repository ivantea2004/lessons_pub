
all: clc


default_functions.o: default_functions.h default_functions.c real.h
	gcc -Wall -c -s default_functions.c -o default_functions.o

root.o: root.c root.h real_function.h real.h
	gcc -Wall -c -s root.c -o root.o

integral.o: integral.c integral.h real_function.h real.h
	gcc -Wall -c -s integral.c -o integral.o

"defined_functions.o": defined_functions.c defined_functions.h default_functions.h real_function.h real.h
	gcc -Wall -c -s defined_function.c -o defined_functions.o

main.o: main.c defined_functions.h integral.h root.h real_function.h real.h
	gcc -Wall -c -s main.c -o main.o

clc: root.o integral.o defined_functions.o main.o default_functions.o
	gcc -Wall -s root.o integral.o defined_functions.o default_functions.o main.o -lm -o clc

clean:
	rm -f clc root.o integral.o defined_functions.o default_functions.o main.o
