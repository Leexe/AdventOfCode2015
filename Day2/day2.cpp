#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;

class wrappingPapper {
    public:
        wrappingPapper() : totalWrapping(0) {}
        void addWrapping(string input);
        void addRibbons(string input);
        void sortArr(int arr[], size_t size);
        int getWrapping() const {return totalWrapping;}
        int getRibbons() const {return totalRibbons;}
        
    private:
        int totalWrapping;
        int totalRibbons;
};

void wrappingPapper::sortArr(int arr[], size_t size) {
    // Bubble Sort Array
    int n = 3;
    while (n > 1) {
        int new_N = 0;
        for (size_t i = 1; i < n; i++) {
            if (arr[i] < arr[i-1]) {
                std::swap(arr[i], arr[i-1]);
                new_N = i;
            }
        }
        n = new_N;
    }
}

void wrappingPapper::addWrapping(string input) {
    std::istringstream iss(input);
    string preNum;
    int nums[3];
    // Insert numbers into array
    for (int i = 0; i < 3; i++) {
        std::getline(iss, preNum, 'x');
        nums[i] = stoi(preNum);
    }
    sortArr(nums, 3);

    totalWrapping += 2*(nums[0]*nums[1] + nums[0]*nums[2] + nums[1]*nums[2]) + nums[0]*nums[1];
}

void wrappingPapper::addRibbons(string input) {
    std::istringstream iss(input);
    string preNum;
    int nums[3];
    for (int i = 0; i < 3; i++) {
        getline(iss, preNum, 'x');
        nums[i] = std::stoi(preNum);
    }
    sortArr(nums, 3);
    totalRibbons += 2*(nums[0]+nums[1]) + (nums[0]*nums[1]*nums[2]);
}

int main() {
    std::ifstream inFS;
    string input;
    wrappingPapper wrapping;

    inFS.open("data.txt");
    if (!inFS.is_open()) {
        cout << "Could not open file" << endl;
        return 1;
    }

    while (!inFS.eof() && inFS.good()) {
        inFS >> input;
        if (!inFS.fail()) {
            wrapping.addWrapping(input);
            wrapping.addRibbons(input);
        }
    }

    inFS.close();

    cout << "Total Wrapping Paper Needed: " << wrapping.getWrapping() << endl;
    cout << "Total Ribbon Needed: " << wrapping.getRibbons() << endl;
}