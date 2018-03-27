main : main.o bigint.o
	g++ -o res main.o bigint.o
main.o : main.cpp
	g++ -g -c -O3 main.cpp
bigint.o : ./classes/bigint.cpp ./classes/bigint.h
	g++ -g -c -O3 ./classes/bigint.cpp
clean:
	rm *.o
