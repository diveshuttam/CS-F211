complileall:	main.o	merge_sort.o
	gcc main.o merge_sort.o -o build

main.o:
	gcc -c main.c

merge_sort.o:
	gcc -c merge_sort.c

clean:
	rm -rf main.o merge_sort.o build
