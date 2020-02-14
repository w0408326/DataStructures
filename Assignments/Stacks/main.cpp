#include <string>

#include "displayMaze.h"

using namespace std;

int main() {
    string maze1("maze1.txt");
    string maze2("maze2.txt");
    string maze3("maze3.txt");
    string maze4("maze4.txt");
    string maze5("maze5.txt");

    for (int i = 1; i <= 5; ++i) {
        displayMaze("maze" + std::to_string(i) + ".txt");
    }

    return 0;
}
