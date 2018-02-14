build: driver.o SeqList.o
	gcc driver.o SeqList.o -o build

driver.o: driver.c SeqList.h
	gcc -c driver.c

SeqList.o: SeqList.c SeqList.h
	gcc -c SeqList.c

clean: build
	rm -f ./build ./SeqList.o ./driver.o
