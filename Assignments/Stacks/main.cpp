#include <iostream>
#include <fstream>

using namespace std;

int main() {

    int row = 2;
    int col = 0;
    char c;


    ifstream maze ("maze.txt");

    while(maze.get(c)){
        if(c != '\n'){
            col++;
        }
        else {
            col = 0;
            row++;
        }
    }

    maze.close();

 //   col = col/row;
    string cols = "+-+-+-+-+-+ +-+ + +-+-+ + +-+ + +-+ + + +-+-+ + +++";

    cout << row << endl;
    cout << col << endl;
    cout << cols.size() << endl;

    char mazeArray[row][col];

    maze.open("maze.txt");
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
         //   maze >> noskipws >> mazeArray[i][j];
            maze.get(c);
            mazeArray[i][j] = c;
        };
    }
    maze.close();

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << mazeArray[i][j];
        }
    }


    return 0;
}
