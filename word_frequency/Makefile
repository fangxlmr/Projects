C_INCLUDE_PATH = ./include
export C_INCLUDE_PATH
vpath %.h ./include
vpath %.c ./src
vpath %.o ./lib

objects = main.o word.o bstree.o

word-count: $(objects)
	gcc -o $@ $(objects)

.PHONY: clean
clean:
	-rm word-count $(objects)
