/*
Find the minimum dictionary distance between two words
Operations permitted are 1) Insert 2) Delete 3) Replace
Input : Two words as strings
Output : Integer
*/

#include <iostream>
using namespace std;


int findMinimumDistance(string word1, string word2){
    
    int word1length = word1.length();
    int word2length = word2.length();
    
    if (word1length == 0) return word2length;
    if (word2length == 0) return word1length;
    
    /*
    If the last character is different
    Find the minimum of distance obtained using the three operations
    */
    
    if (word1[word1length-1] == word2[word2length-1]){
        return findMinimumDistance(word1.substr(0,word1length-1), word2.substr(0,word2length-1));
    }
    
    int insertDistance = findMinimumDistance(word1.substr(0,word1length-1), word2);
    int deleteDistance =  findMinimumDistance(word1, word2.substr(0,word2length-1));
    int replaceDistance = findMinimumDistance(word1.substr(0,word1length-1), word2.substr(0,word2length-1));
    
    int minDistance = min(insertDistance,deleteDistance);
    minDistance = min(minDistance,replaceDistance);
    
    return minDistance + 1;
    
}


int main(){
    string word1 = "hiddentalent";
    string word2 = "hiddentalentreal";
    int distance = findMinimumDistance(word1,word2);
    cout<<"Minimum Distance between "<<word1<<" & "<<word2<<" is :"<< distance<<endl;
}