#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>

using namespace std;

int main() {

    int count = 0;

    int row = 0;
    int col = 0;

    string line;
    ifstream mazeRowColCount("maze.txt");

    if(mazeRowColCount){
        while(getline(mazeRowColCount, line)){
            row++;
        }

        mazeRowColCount.close();
    }

    col = line.length();

    char linearray[col];
    char array[row][col];

    ifstream mazeInput("maze.txt");

    if(mazeInput)
    {
        while (getline(mazeInput, line))
        {
            fill_n(linearray, col, 0);
            strcpy(linearray, line.c_str());

            for (int i = 0; i < col; ++i) {
                if(linearray[i] == '\000'){
                    array[count][i] = ' ';
                }else{
                    array[count][i] = linearray[i];
                }
            }
            count++;
        }
        mazeInput.close();
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << array[i][j];
        }
        cout << endl;
    }

    int currentRow = 1;
    int currentCol = 0;

    stack<int> x;
    stack<int> y;

    x.push(1);
    y.push(0);

    while(array[row-2][col-1] != '#'){
        array[x.top()][y.top()] = '#';

        if(array[x.top()][y.top()+1] == ' '){
            array[x.top()][y.top()+1] = '#';
            x.push(x.top());
            y.push(y.top()+1);
        }else if(array[x.top()+1][y.top()] == ' '){
            array[x.top()+1][y.top()] = '#';
            x.push(x.top()+1);
            y.push(y.top());
        }else if(array[x.top()][y.top()-1] == ' '){
            array[x.top()][y.top()-1] = '#';
            x.push(x.top());
            y.push(y.top()-1);
        }else if(array[x.top()-1][y.top()] == ' '){
            array[x.top()-1][y.top()] = '#';
            x.push(x.top()-1);
            y.push(y.top());
        }else{
            array[x.top()][y.top()] = '*';
            x.pop();
            y.pop();
        }

//        array[currentRow][currentCol] = '#';
//
//        if(array[currentRow][currentCol+1] == ' '){
//            array[currentRow][currentCol+1] = '#';
//            currentCol++;
//        }else if(array[currentRow+1][currentCol] == ' '){
//            array[currentRow+1][currentCol] = '#';
//            currentRow++;
//        }else if(array[currentRow][currentCol-1] == ' '){
//            array[currentRow][currentCol-1] = '#';
//            currentCol--;
//        }else if(array[currentRow-1][currentCol] == ' '){
//            array[currentRow-1][currentCol] = '#';
//            currentRow--;
//        }
    }


    cout << endl << "Solved:" << endl;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << array[i][j];
        }
        cout << endl;
    }
    return 0;
}
