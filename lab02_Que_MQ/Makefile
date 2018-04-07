build: driverQ.o que.o que.c que.h driver.c
	gcc -g driverQ.o que.o -o build

que.o: que.c que.h
	gcc -c que.c

driverQ.o: driverQ.c que.h
	gcc -c driverQ.c

clean:
	rm driverQ.o que.o build
