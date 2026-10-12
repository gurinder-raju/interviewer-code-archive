/*
Depth-first search of a graph stored as an adjacency list, visiting each node once.
*/

using namespace std;
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>

class Graph {
  public: 
    void addEdge(string s1, string s2){
        list<string> & neighbors = nodeToAList[s1];
        neighbors.insert(neighbors.end(),s2);
    }
    list<string> getNeighbors(string s){
        list<string> neighbors = nodeToAList[s];
        return neighbors;
    }
    //Give a root
    string getRoot(){
        unordered_map<string,list<string>>::iterator it = nodeToAList.begin();
        if (it != nodeToAList.end()){
            return (*it).first;
        }
        return "";
    }
  private:
    //given a string, find its adjacency list
    unordered_map<string,list<string>> nodeToAList;
};

void depthFirstSeach2(Graph & g, string & currString, unordered_set<string> & visitedNodes){
    unordered_set<string>::iterator it = visitedNodes.find(currString);
    if (it == visitedNodes.end()){
        cout<<currString<<"->";
        visitedNodes.insert(visitedNodes.end(),currString);
        list<string> neighbors = g.getNeighbors(currString);
        list<string>::iterator it2 = neighbors.begin();
        while (it2 != neighbors.end()){
            depthFirstSeach2(g,(*it2),visitedNodes);
            it2++;
        }
    }
    return;
}

void depthFirstSeach(Graph & g){
    unordered_set<string> visitedNodes;
    string root = g.getRoot();
    depthFirstSeach2(g,root,visitedNodes);
    return;
}

int main(){
    Graph g;
    
    g.addEdge("5", "2");
    g.addEdge("5", "0");
    g.addEdge("4", "0");
    g.addEdge("4", "1");
    g.addEdge("2", "3");
    g.addEdge("3", "1");

    
    cout<<"DepthFirstSearch: ";
    depthFirstSeach(g);
    cout<<endl;

    return 0;
    
}