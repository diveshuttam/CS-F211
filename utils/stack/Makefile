build: Stack.o driver.o SeqList.o StackIO.o
	gcc -g Stack.o driver.o SeqList.o StackIO.o -o build

Stack.o: Stack.c Stack.h SeqList.h
	gcc -g -c Stack.c

SeqList.o: SeqList.c SeqList.h
	gcc -g -c SeqList.c

StackIO.o: StackIO.c StackIO.h Stack.h
	gcc -g -c StackIO.c
