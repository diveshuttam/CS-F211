#main build starts here
build: driver.o SeqList.o SeqListIO.o
	gcc -g driver.o SeqList.o SeqListIO.o -o build

driver.o: driver.c SeqList.h SeqListIO.h
	gcc -g -c driver.c

SeqList.o: SeqList.c SeqList.h
	gcc -g -c SeqList.c

SeqListIO.o: SeqListIO.h SeqList.h SeqListIO.c
	gcc -g -c SeqListIO.c

#buildTest starts here
buildTest: SeqListUses.o SeqListTest.o SeqList.o SeqListIO.o
	gcc -g SeqListUses.o SeqListTest.o SeqList.o SeqListIO.o -o buildTest

SeqListUses.o: SeqListUses.c SeqListUses.h SeqList.h
	gcc -g -c SeqListUses.c

SeqListTest.o: SeqListTest.c SeqList.h SeqListUses.h SeqListIO.h
	gcc -g -c SeqListTest.c

clean:
	rm -f ./build ./SeqList.o ./driver.o ./buildTest ./SeqListUses.o ./SeqListTest.o ./SeqListIO.o
