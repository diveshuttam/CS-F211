build:	tree.o driver.o
	gcc -g tree.o driver.o -o build

BinaryTree.o: BinaryTree.c BinaryTree.h
	gcc -c -g BinaryTree.c

driver.o:	driver.c
	gcc -c -g driver.c

buildStack: Stack.o driver.o SeqList.o StackIO.o
	gcc -g Stack.o driver.o SeqList.o StackIO.o -o build

Stack.o: Stack.c Stack.h SeqList.h
	gcc -g -c Stack.c

SeqList.o: SeqList.c SeqList.h
	gcc -g -c SeqList.c

StackIO.o: StackIO.c StackIO.h Stack.h
	gcc -g -c StackIO.c
