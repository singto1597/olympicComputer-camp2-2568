CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = out
OBJS = kruskal.o dsu.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

kruskal.o: kruskal.cpp dsu.h
	$(CXX) $(CXXFLAGS) -c kruskal.cpp

dsu.o: dsu.cpp dsu.h
	$(CXX) $(CXXFLAGS) -c dsu.cpp

clean:
	rm -f $(OBJS) $(TARGET)