CC=g++ -std=c++11 -g
exe=asm4

$(exe): main.cpp bats.o event.o game.o gold.o room.o stalactites.o wumpus.o
	$(CC) main.cpp bats.o event.o game.o gold.o room.o stalactites.o wumpus.o -o $(exe)

bats.o: bats.cpp
	$(CC) -c bats.cpp

event.o: event.cpp
	$(CC) -c event.cpp

game.o: game.cpp
	$(CC) -c game.cpp

gold.o: gold.cpp
	$(CC) -c gold.cpp

room.o: room.cpp
	$(CC) -c room.cpp

stalactites.o: stalactites.cpp
	$(CC) -c stalactites.cpp

wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp

clean: 
	rm -f *.o *.out $(exe)
