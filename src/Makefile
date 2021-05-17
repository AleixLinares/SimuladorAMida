main: EventScheduler.cpp EventScheduler.h Esdeveniment.o Object.o
	g++ -g -Wall -o main.exe EventScheduler.cpp Esdeveniment.o Object.o

Esdeveniment.o: Esdeveniment.cpp Esdeveniment.h Object.h Object.o
	g++ -g -Wall -c Esdeveniment.cpp

Object.o: Object.cpp Object.h
	g++ -g -Wall -c Object.cpp

.PHONY: clean
clean:
	rm -rf *.o
