CXX = g++
CXXFLAGS = -std=c++17 -Wall
BINARIES = day1

all: $(BINARIES)

day1: day1.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

tests: $(BINARIES)
	./day1

clean:
	/bin/rm *.o $(BINARIES)