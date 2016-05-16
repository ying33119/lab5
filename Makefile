hugeint: HugeInt.o main.o
	g++ -o hugeint main.o HugeInt.o

HugeInt.o: HugeInt.cpp HugeInt.h
	g++ -c HugeInt.cpp

main.o: main.cpp HugeInt.h
	g++ -c main.cpp