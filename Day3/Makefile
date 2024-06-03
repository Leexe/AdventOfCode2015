CXX = g++
CXXFLAGS = -Wall -Werror -std=c++17 
BINARIES = day3

all: $(BINARIES)

day3: day3.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

tests: $(BINARIES)
	./day3

clean:
	/bin/rm -f *.o $(BINARIES)