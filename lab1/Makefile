build: driver.o SeqList.o
	gcc driver.o SeqList.o -o build

driver.o: driver.c
	gcc -c driver.c

SeqList.o: SeqList.c
	gcc -c SeqList.c

clean:
	rm -f ./build ./SeqList.o ./driver.o ./buildTest ./SeqListUses.o ./SeqListTest.o

buildTest: SeqListUses.o SeqListTest.o SeqList.o
	gcc SeqListUses.o SeqListTest.o SeqList.o -o buildTest

SeqListUses.o: SeqListUses.c
	gcc -c SeqListUses.c

SeqListTest.o: SeqListTest.c
	gcc -c SeqListTest.c
