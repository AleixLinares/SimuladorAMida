main: EventScheduler.cpp Esdeveniment.o Object.o Entitat.o Source.o Peatge.o Queue.o
	g++ -g -Wall -o main.exe EventScheduler.cpp ./compiled/Object.o ./compiled/Entitat.o ./compiled/Source.o ./compiled/Esdeveniment.o ./compiled/Peatge.o

Entitat.o: ./objectes/Entitat.cpp
	g++ -g -Wall -c -o ./compiled/Entitat.o ./objectes/Entitat.cpp

Object.o: ./objectes/Object.cpp
	g++ -g -Wall -c -o ./compiled/Object.o ./objectes/Object.cpp

Source.o: ./objectes/Source.cpp
	g++ -g -Wall -c -o ./compiled/Source.o ./objectes/Source.cpp

Peatge.o: ./objectes/Peatge.cpp
	g++ -g -Wall -c -o ./compiled/Peatge.o ./objectes/Peatge.cpp

Peatge.o: ./objectes/Queue.cpp
	g++ -g -Wall -c -o ./compiled/Queue.o ./objectes/Queue.cpp

Esdeveniment.o: Esdeveniment.cpp
	g++ -g -Wall -c -o ./compiled/Esdeveniment.o Esdeveniment.cpp

.PHONY: clean
clean:
	rm -rf *.o
