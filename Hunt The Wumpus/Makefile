hunt_the_wumpus: main.o gameflow.o room.o event.o pit.o bat.o gold.o hunter.o wumpus.o
	g++ -o hunt_the_wumpus main.o gameflow.o room.o event.o pit.o bat.o gold.o hunter.o wumpus.o
main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp
gameflow.o: gameflow.cpp
	g++ -std=c++11 -g -c gameflow.cpp
room.o: room.cpp
	g++ -std=c++11 -g -c room.cpp
event.o: event.cpp
	g++ -std=c++11 -g -c event.cpp
wumpus.o: wumpus.cpp
	g++ -std=c++11 -g -c wumpus.cpp
pit.o: pit.cpp
	g++ -std=c++11 -g -c pit.cpp
bat.o: bat.cpp
	g++ -std=c++11 -g -c bat.cpp
gold.o: gold.cpp
	g++ -std=c++11 -g -c gold.cpp
hunter.o: hunter.cpp
	g++ -std=c++11 -g -c hunter.cpp
clean:
	rm -f *.o hunt_the_wumpus

