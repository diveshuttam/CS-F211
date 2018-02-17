build: driver.o SeqList.o
	gcc -g driver.o SeqList.o -o build

driver.o: driver.c SeqList.h
	gcc -g -c driver.c

SeqList.o: SeqList.c SeqList.h
	gcc -g -c SeqList.c

buildTest: SeqListUses.o SeqListTest.o SeqList.o
	gcc -g SeqListUses.o SeqListTest.o SeqList.o -o buildTest

SeqListUses.o: SeqListUses.c SeqListUses.h SeqList.h
	gcc -g -c SeqListUses.c

SeqListTest.o: SeqListTest.c SeqList.h SeqListUses.h
	gcc -g -c SeqListTest.c

clean:
	rm -f ./build ./SeqList.o ./driver.o ./buildTest ./SeqListUses.o ./SeqListTest.o
