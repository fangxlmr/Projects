wf: wf.o minheap.o bstree.o
	gcc -o wf wf.o minheap.o bstree.o

wf.o: bstree.h minheap.h
minheap.o: bstree.h

.Phony: clean
clean: 
	-rm wf bstree.o minheap.o wf.o

