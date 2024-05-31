#include <iostream>
#include <string>
#include <fstream>
#include <map>
using std::cout;
using std::string;
using std::endl;
using std::cin;

class positionDNE {};

int getRoom(string str) {
    int result = 0;

    for (char c : str) {
        if (c == '(')
            result++;
        else 
            result--;
    }

    return result;
}

int getPos(string str, int desiredRoom) {
    int room = 0;
    int position = 0;
    
    if (desiredRoom == 0) 
        return position;

    for (char c : str) {
        position++;
        if (c == '(')
            room++;
        else 
            room--;
        if (room == desiredRoom) 
            return position;
    }

    throw positionDNE();
}

int main() {
    std::ifstream inFS;
    string fileName;
    string code;
    string input = "";
    std::map<string, int> commands;

    commands["help"] = 0;
    commands["getfloor"] = 1;
    commands["getposition"] = 2;
    commands["exit"] = 3;

    cout << "Insert File Name: ";
    cin >> fileName;

    inFS.open(fileName);
    if (!inFS.is_open()) {
        cout << "Couldn't open the file" << endl;
        return 1;
    }

    inFS >> code;
    inFS.close();

    while (input != "exit") {
        cout << "Enter a command ('exit' to exit and 'help' for commands): ";
        cin >> input;
        transform(input.begin(), input.end(), input.begin(), tolower);
        if (commands.find(input) != commands.end()) {
            int cmdNumber = commands[input];
            if (cmdNumber == 0) {
                int j = 0;
                for (std::map<string, int>::iterator i = commands.begin(); i != commands.end(); i++) {
                    cout << j << ". " << i->first << endl;
                    j++;
                }
            }
            else if (cmdNumber == 1) {
                cout << "The floor that santa should go to is: " << getRoom(input) << endl;
            }
            else if (cmdNumber == 2) {
                int room;
                cout << "Enter a room number: ";
                try {
                    cin >> room;
                    int result = getPos(code, room);
                    cout << "The position to get to room " << room << " is: " << result << endl;
                }
                catch (positionDNE) {
                    cout << "The room entered was never visted" << endl;
                }
            }
            else if (cmdNumber == 3) {
                cout << "Program Exited" << endl;
            }
        }
        else {
            cout << "ERROR: Not a real command!" << endl;
        }
    }
} 