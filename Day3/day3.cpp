#include <iostream>
#include <fstream>
#include <set>
#include <utility>
#include <string>

class Plane {
    public:
        Plane();
        void visit(char c, bool enableRobo);
        int getVisited() const {return coord_visted.size();}
    private:
        std::set<std::pair<int,int>> coord_visted;
        // currCoords[0] and currCoords[1] are positions in the x and y direction respectively
        std::pair<int, int> currCoords;
        std::pair<int, int> roboCurrCoords;
        bool santaMoves;
        void move(char& c, bool enableRobo);
};

Plane::Plane() {
    currCoords = std::make_pair(0,0);
    roboCurrCoords = std::make_pair(0,0);
    santaMoves = true;
    coord_visted.insert(std::make_pair(0,0));
}

void Plane::move(char& c, bool enableRobo = false) {
    if (c == '<') {
        if (enableRobo)
            roboCurrCoords.first--;
        else 
            currCoords.first--;
    }
    else if (c == '>') {
        if (enableRobo)
            roboCurrCoords.first++;
        else 
            currCoords.first++;
    }
    else if (c == '^') {
        if (enableRobo)
            roboCurrCoords.second++;
        else 
            currCoords.second++;
    }
    else if (c == 'v') {
        if (enableRobo)
            roboCurrCoords.second--;
        else 
            currCoords.second--;
    }
}

void Plane::visit(char c, bool enableRobo = false) {
    if (enableRobo) {
        move(c, santaMoves);
        santaMoves = !santaMoves;
    }
    else 
        move(c);
    // If the current coordinates have not been visited, update the visited x and y sets and increment `visited`
    if (coord_visted.find(currCoords) == coord_visted.end()) {
        coord_visted.insert(currCoords);
    }
    else if (coord_visted.find(roboCurrCoords) == coord_visted.end()) {
        coord_visted.insert(roboCurrCoords);
    }
}

int main() {
    std::ifstream inFS;
    std::string input;
    Plane plane;

    inFS.open("data.txt");
    if (!inFS.is_open()) {
        std::cout << "ERROR: Couldn't open file!" << std::endl;
        return 1;
    }
    inFS >> input;
    inFS.close();

    for (char c : input) {
        plane.visit(c, true);
    }

    std::cout << "Total houses visited: " << plane.getVisited() << std::endl;

    return 0;
}