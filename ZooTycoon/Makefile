CC = g++ -g
exe_file = zootycoon

$(exe_file): main.o zoo.o tiger.o sealion.o blackbear.o animal.o
	$(CC) main.o zoo.o tiger.o sealion.o blackbear.o animal.o -o $(exe_file)

main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)

zoo.o: zoo.cpp
	$(CC) -c zoo.cpp $(CFLAGS)

tiger.o: tiger.cpp
	$(CC) -c tiger.cpp $(CFLAGS)

sealion.o: sealion.cpp
	$(CC) -c sealion.cpp $(CFLAGS)

blackbear.o: blackbear.cpp
	$(CC) -c blackbear.cpp $(CFLAGS)

animal.o: animal.cpp
	$(CC) -c animal.cpp $(CFLAGS)
	
	clean:
	rm -f *.out *.o $(exe_file)
	.PHONY: clean
