#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {

    int count = 0;

    int row = 0;
    int col = 0;

    string line;
    ifstream mymaze("maze.txt");

    char linearray[55];
    char array[25][55];

    

    if(mymaze)
    {
        while (getline(mymaze,line))
        {
            //cout << line << endl;
            fill_n(linearray, 55, 0);
            strcpy(linearray, line.c_str());

            for (int i = 0; i < 55; ++i) {
                if(linearray[i] == '\000'){
                    array[count][i] = ' ';
                }else{
                    array[count][i] = linearray[i];
                }
            }
            count++;
        }
        mymaze.close();
    }

//    char c;
//
//
//    ifstream maze ("maze.txt");
//
//    while(maze.get(c)){
//        if(c != '\n'){
//            col++;
//        }
//        else {
//            col = 0;
//            row++;
//        }
//    }
//
//    maze.close();
//
// //   col = col/row;
//    string cols = "+-+-+-+-+-+ +-+ + +-+-+ + +-+ + +-+ + + +-+-+ + +++";
//
//    cout << row << endl;
//    cout << col << endl;
//    cout << cols.size() << endl;
//
//    char mazeArray[row][col];
//
//    maze.open("maze.txt");
//    for (int i = 0; i < row; ++i) {
//        for (int j = 0; j < col; ++j) {
//         //   maze >> noskipws >> mazeArray[i][j];
//            maze.get(c);
//            mazeArray[i][j] = c;
//        };
//    }
//    maze.close();
//
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 55; ++j) {
            cout << array[i][j];
        }
        cout << endl;
    }


    return 0;
}
