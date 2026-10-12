/*
Minimum path sum in a matrix from top to bottom
*/

using namespace std;
#include <iostream>
#include <vector>
#include <climits> //added later: latest compilers reject INT_MAX without it

int min(int a, int b){
    int min; 
    min = a > b ? b : a;
    return min;
}

int minPath(vector<vector<int>> matrix, int row, int col){
    if (row == 1 && col == 1) return matrix[0][0];
    if (row == 0 || col == 0) return INT_MAX;
    
    int pathUp = minPath(matrix,row-1,col);
    int pathLeft = minPath(matrix,row,col-1);
    
    return min(pathUp,pathLeft)+matrix[row-1][col-1];
    
}

int minPathDP(vector<vector<int>> matrix){
    vector<vector<int>> dp = matrix;
    
    for (int i = 1; i < matrix.size();i++){
        dp[i][0] = dp[i-1][0] + matrix[i][0];

    }
    
    for (int j = 1; j < matrix[0].size(); j++){
        dp[0][j] = dp[0][j-1] + matrix[0][j];
    }
    
    for (int i = 1; i < matrix.size();i++){
        for (int j = 1; j < matrix[0].size(); j++){
            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + matrix[i][j];
        }
    }

    return dp[matrix.size()-1][matrix[0].size()-1];
}



int minPath(vector<vector<int>> matrix){
    if (matrix.size() == 0 || matrix[0].size() == 0) return INT_MAX;
    return minPath(matrix,matrix.size(), matrix[0].size());
}

int main(){
    vector<vector<int>> matrix;
    matrix = {{1,3,1},
                {1,5,1},
                {4,2,1}};
    cout<<minPath(matrix)<<endl;
    cout<<minPathDP(matrix)<<endl;
    return 0;
}