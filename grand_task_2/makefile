
all: clc

differentiable_function_t.h:

root.h: differentiable_function_t.h
root.c: root.h

integral.h: differentiable_function_t.h
integral.c: integral.h

"defined_functions.h": differentiable_function_t.h
"defined_functions.c": defined_functions.h

main.c: defined_functions.h integral.h root.h

clc: main.c root.c integral.c defined_functions.c
	gcc -Wall -s main.c root.c integral.c defined_functions.c -lm -o clc

clean:
	rm -f clc 
