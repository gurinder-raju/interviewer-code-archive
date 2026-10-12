/*
Graph coloring: given a graph as an adjacency matrix and m colors, assign a color
to every node so that no two adjacent nodes share a color.
*/

#include <iostream>
using namespace std;


template <int numNodes>
void printGraph(int (&graph)[numNodes][numNodes]){
    for (int y = 0 ; y < numNodes; y++){
        for (int x = 0 ; x < numNodes; x++){
            cout << "|" << graph [y][x];
        }
         cout << "|" << endl;
    }
    cout << endl;
}

template <int numNodes>
bool isNodeColorValid (int (&graph)[numNodes][numNodes], int nodeNum, int color){
    int row = nodeNum;
    int column = nodeNum-1;
    while (column >= 0){
        if (graph[row][column] == 1 && graph[column][column] == color){
            return false;
        }
        column--;
    }
    return true;
}

template <int numNodes> 
void solveGraphColoring (int (&graph)[numNodes][numNodes], int numOfColors, int startNode=0){
    
    if (startNode == numNodes){
        //an acceptable color decision has been made for the entire graph
        printGraph(graph);
        return;
    }
    
    int row = startNode;

    for (int color=2; color < numOfColors+2; color++){
            if (isNodeColorValid(graph, row, color)) {
                graph[row][row] = color;
                solveGraphColoring(graph, numOfColors,row+1);
            }
    }
}    


int main()
{
    int graph[4][4] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    solveGraphColoring(graph,3);
}