using namespace std;
#include <iostream>
#include <queue>


template <int rows,int columns>
void traverseIsland(pair<int,int> position, int (&grid)[rows][columns]){
    
    queue<pair<int,int>> traversalQueue;
    traversalQueue.push(position);
    
    while(traversalQueue.size() != 0){
        
        pair<int,int> frontPosition = traversalQueue.front();
        int i = frontPosition.first;
        int j = frontPosition.second;
        grid[i][j] = -1;
        
        traversalQueue.pop();
        
        if(i > 0 && grid[i-1][j] == 1){
            //safely check the left of this position
            traversalQueue.push(pair<int,int>(i-1,j));
        }
        if( i < rows-1 && grid[i+1][j] == 1){
            //safely check the right of this position
            traversalQueue.push(pair<int,int>(i+1,j));
        }
        if(j > 0 && grid[i][j-1] == 1){
            //safely check the upper of this position
            traversalQueue.push(pair<int,int>(i,j-1));
        }
        if(j < columns-1 && grid[i][j+1] == 1){
            //safely check the lower of this position
            traversalQueue.push(pair<int,int>(i,j+1));
        }
    }
    //island has been traversed
    return;
}

template <int rows,int columns>
int findNumberOfIslands(int (&grid)[rows][columns]){
     int numOfIslands = 0;
     for (int i = 0; i < rows; i++){
         for (int j = 0; j < columns; j++){
             if(grid[i][j] == 1){
                 numOfIslands++;
                 traverseIsland(pair<int,int>(i,j),grid);
             }
         }
     }
     return numOfIslands;
}

template <int numRows, int numColumns>
void printGrid(int (&grid)[numRows][numColumns]){

    for (int y = 0 ; y < numRows; y++){
        for (int x = 0 ; x < numColumns; x++){
            cout << "|" << grid [y][x];
        }
         cout << "|" << endl;
    }
    cout << endl;
}


int main(){
    int grid1[4][5] = {
                    {1,1,0,0,0},
                    {1,1,0,0,0},
                    {0,0,1,0,0},
                    {0,0,0,1,1}
                    };
    int grid2[4][5] = {
                    {1,1,1,1,0},
                    {1,1,0,1,0},
                    {1,1,0,1,0},
                    {0,0,0,1,1}
                    };
    cout<<"Number of Island is: "<<findNumberOfIslands(grid2)<<endl;
    printGrid(grid2);
    return 0;
}