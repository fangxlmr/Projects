C_INCLUDE_PATH=./include/
export C_INCLUDE_PATH
vpath %.c ./src/
vpath %.h ./include/

wf: wf.o minheap.o bstree.o file.o
	gcc -o wf wf.o minheap.o bstree.o file.o

wf.o: bstree.h minheap.h file.h
minheap.o: bstree.h

.Phony: clean
clean: 
	-rm wf wf.o bstree.o minheap.o file.o

