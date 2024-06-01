CXX = g++
CXXFLAGS = -Wall -Werror -std=c++17
BINARIES = day2

all: $(BINARIES)

tests: $(BINARIES)
	./day2

day2: day2.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean: 
	/bin/rm -f *.o $(BINARIES)