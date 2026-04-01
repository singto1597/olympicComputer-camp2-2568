CXX = g++

all: label

clean:
	rm -f *.o label

bmplib.o: bmplib.cpp bmplib.h
	$(CXX) -c bmplib.cpp -o bmplib.o -g

dsu.o: dsu.cpp dsu.h
	$(CXX) -c dsu.cpp -o dsu.o -g

label: label.cpp bmplib.o dsu.o
	$(CXX) label.cpp bmplib.o dsu.o -o label -g