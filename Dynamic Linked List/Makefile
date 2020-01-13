CC = g++ -g
exe_file = linkedlist

$(exe_file): main.o linked_list.o
	$(CC) main.o linked_list.o -o $(exe_file)
main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)
linked_list.o: linked_list.cpp
	$(CC) -c linked_list.cpp $(CFLAGS)

clean:
	rm -f *.out *.o $(exe_file)
.PHONY: clean
