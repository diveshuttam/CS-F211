compare: compRecMS compIterMS
	#time profiling
	./buildRec > /dev/null
	gprof buildRec > recursive_gprof.log
	rm gmon.out
	./buildIter > /dev/null
	gprof buildIter > iterative_gprof.log
	rm gmon.out

compRecMS: main.o merge.o merge_sort_recursive.o
	gcc -pg main.o merge.o merge_sort_recursive.o -o buildRec

compIterMS: main.o merge.o merge_sort_iterative.o
	gcc -pg main.o merge.o merge_sort_iterative.o -o buildIter

main.o: main.c merge_sort.h
	gcc -pg -c main.c

merge.o: merge_sort.h merge.c
	gcc -pg -c merge.c


merge_sort_iterative.o: merge_sort.h merge.c merge_sort_iterative.c
	gcc -pg -c merge_sort_iterative.c

merge_sort_recursive.o: merge_sort.h merge.c merge_sort_recursive.c
	gcc -pg -c merge_sort_recursive.c

clean:
	rm -f  main.o merge.o merge_sort_iterative.o merge_sort_recursive.o buildRec buildIter

compareMem: compRecMem compIterMem
	#memory profiling
	valgrind ./buildRec > /dev/null 2>recursive_valgrind.log
	valgrind ./buildIter > /dev/null 2>iterative_valgrind.log

compRecMem: mainm.o mergem.o merge_sort_recursivem.o
	gcc main.o merge.o merge_sort_recursive.o -o buildRec

compIterMem: mainm.o mergem.o merge_sort_iterativem.o
	gcc main.o merge.o merge_sort_iterative.o -o buildIter

mainm.o: main.c merge_sort.h
	gcc -c main.c

mergem.o: merge_sort.h merge.c
	gcc -c merge.c


merge_sort_iterativem.o: merge_sort.h merge.c merge_sort_iterative.c
	gcc -c merge_sort_iterative.c

merge_sort_recursivem.o: merge_sort.h merge.c merge_sort_recursive.c
	gcc -c merge_sort_recursive.c
