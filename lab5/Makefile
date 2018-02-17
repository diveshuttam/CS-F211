complileall: main.o merge_sort.o
	gcc -g main.o merge_sort.o -o build

main.o: main.c merge_sort.h merge_sort.c
	gcc -g -c main.c

merge_sort.o: merge_sort.h merge_sort.c
	gcc -g -c merge_sort.c

clean:
	rm -rf main.o merge_sort.o build
