/*
N-Queens: place N queens on an N x N chessboard so that no two queens attack each
other (same row, column or diagonal).
*/

#include <iostream>
using namespace std;

template <int numRows, int numColumns>
void printQueenPlacements(int (&board)[numRows][numColumns]){

    for (int y = 0 ; y < numRows; y++){
        for (int x = 0 ; x < numColumns; x++){
            cout << "|" << board [y][x];
        }
         cout << "|" << endl;
    }
    cout << endl;
}

template <int numRows, int numColumns>
bool isValidQueenPlacement (int (&board)[numRows][numColumns], int xPosition, int yPosition){
    
    //index counters used for iteratively checking clashing queen positions
    int xIndex = xPosition-1;
    int yIndex = yPosition-1;
    
    //check for another queen present diagonally up from this position
    while (xIndex >= 0 && yIndex >= 0){
        if (board[yIndex][xIndex] == 1){
            return false;
        }
        xIndex--;
        yIndex--;
    }
    
    //check for another queen present diagonally down from this position
    xIndex = xPosition-1;
    yIndex = yPosition+1;
    while (xIndex >= 0 && yIndex < numRows){
        if (board[yIndex][xIndex] == 1){
            return false;
        }
        xIndex--;
        yIndex++;
    }
    
    //check for another queen present horizontally left from this position
    xIndex = xPosition - 1;
    while (xIndex >= 0){
        if (board[yPosition][xIndex] == 1){
            return false;
        }
        xIndex--;
    }

    
    //all preceding diagonal positions are empty
    return true;
}

template <int numRows, int numColumns>
void solveNQueens(int (&board)[numRows][numColumns], int numQueens, int xIndex=0){
    
    if (numQueens <= 0) return;
    
    for (;xIndex < numColumns; xIndex++){
        for (int yIndex=0;yIndex < numRows;yIndex++){
            if (isValidQueenPlacement(board,xIndex,yIndex)) {
                board[yIndex][xIndex] = 1;
                numQueens--;
                if (numQueens == 0) {
                    printQueenPlacements(board);
                    board[yIndex][xIndex] = 0;
                    numQueens++;
                } else {
                    solveNQueens(board,numQueens, xIndex+1);
                    board[yIndex][xIndex] = 0;
                    numQueens++;
                }
            }
        }
        
    }
}

int main()
{
    int board[10][10] = {{}};
    solveNQueens(board,9);
}