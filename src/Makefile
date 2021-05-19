main: EventScheduler.cpp EventScheduler.h Esdeveniment.o Object.o Entitat.o Source.o
	g++ -g -Wall -o main.exe EventScheduler.cpp Object.o Entitat.o Source.o Esdeveniment.o

Entitat.o: Entitat.cpp Entitat.h
	g++ -g -Wall -c Entitat.cpp

Object.o: Object.cpp Object.h
	g++ -g -Wall -c Object.cpp

Source.o: Source.cpp Source.h Esdeveniment.o
	g++ -g -Wall -c Source.cpp Esdeveniment.o

Esdeveniment.o: Esdeveniment.cpp Esdeveniment.h
	g++ -g -Wall -c Esdeveniment.cpp

.PHONY: clean
clean:
	rm -rf *.o
