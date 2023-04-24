
TARGET = clc
SRC = main.c root.h root.c integral.h integral.c func_t.h funcs.h funcs.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	gcc -Wall -s $(SRC) -lm -o $(TARGET)

clean:
	rm -f $(TARGET)
