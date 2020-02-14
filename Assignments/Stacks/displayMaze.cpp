#include "displayMaze.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stack>

using namespace std;

void displayMaze(string mazeTxt){
    int count = 0;

    int row = 0;
    int col = 0;

    string line;

    //logic to count number of rows and columns in maze
    ifstream mazeRowColCount(mazeTxt);

    if(mazeRowColCount){
        while(getline(mazeRowColCount, line)){
            row++;
        }

        mazeRowColCount.close();
    }

    col = line.length();

    char lineArray[col];
    char mazeArray[row][col];

    //logic to add maze characters into 2D array
    ifstream mazeInput(mazeTxt);

    if(mazeInput)
    {
        while (getline(mazeInput, line))
        {
            fill_n(lineArray, col, 0);
            strcpy(lineArray, line.c_str());

            for (int i = 0; i < col; ++i) {
                if(lineArray[i] == '\000'){
                    mazeArray[count][i] = ' ';
                }else{
                    mazeArray[count][i] = lineArray[i];
                }
            }
            count++;
        }
        mazeInput.close();
    }

    //printing maze 2D array
    cout << mazeTxt << ":" << endl;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << mazeArray[i][j];
        }
        cout << endl;
    }

    //solving the maze code

    //initializing stacks for x/y coordinates
    stack<int> x;
    stack<int> y;

    //starting point in the maze is the first thing on the stack
    x.push(1);
    y.push(0);

    while(mazeArray[row - 2][col - 1] != '#'){ //while not the ending point
        mazeArray[x.top()][y.top()] = '#';

        if(mazeArray[x.top()][y.top() + 1] == ' '){ // East
            mazeArray[x.top()][y.top() + 1] = '#';
            x.push(x.top());
            y.push(y.top()+1);
        }else if(mazeArray[x.top() + 1][y.top()] == ' '){ // South
            mazeArray[x.top() + 1][y.top()] = '#';
            x.push(x.top()+1);
            y.push(y.top());
        }else if(mazeArray[x.top()][y.top() - 1] == ' '){ // West
            mazeArray[x.top()][y.top() - 1] = '#';
            x.push(x.top());
            y.push(y.top()-1);
        }else if(mazeArray[x.top() - 1][y.top()] == ' '){ // North
            mazeArray[x.top() - 1][y.top()] = '#';
            x.push(x.top()-1);
            y.push(y.top());
        }else{                                            // Go back
            mazeArray[x.top()][y.top()] = '*';
            x.pop();
            y.pop();
        }

    }

    //Printing solved maze
    cout << endl << "Solved:" << endl;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << mazeArray[i][j];
        }
        cout << endl;
    }

    cout << endl;

    //writing maze 2D array to file
    mazeTxt.erase(5,4);
    ofstream outMaze(mazeTxt + "solved.txt");

    //cleaning the maze output
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if(mazeArray[i][j] == '*'){
                mazeArray[i][j] = ' ';
            }
        }
    }


    if(outMaze.is_open())
    {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                outMaze << mazeArray[i][j];
            }
            outMaze << endl;
        }
        outMaze.close();
    }else cout << "Unable to open file";
}