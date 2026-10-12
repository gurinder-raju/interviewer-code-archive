/*
Word ladder: transform a start word into an end word by changing one letter at a time,
where every intermediate word must be in the dictionary. Find the length of the
shortest transformation, and the sequence of words itself.
*/

using namespace std;
#include <iostream>
#include <set>
#include <queue>
#include <list>

int findDistance(string s1, string s2){
    if(s1.length() != s2.length()) return -1;
    int distance = 0;
    for (int i = 0; i < s1.length(); i++){
        if (s1[i] != s2[i]) distance++;
    }
    return distance;
}

list<string> findAndRemoveNeighbors(set<string> & dictionary, string word){
    list<string> neighbors;
    set<string>::iterator it = dictionary.begin();
    set<string>::iterator it2;
    while (it != dictionary.end()){
        string currString = *it;
        if (currString.length() == word.length()){
            if (findDistance(currString,word) == 1){
                neighbors.insert(neighbors.end(),currString);
                it2 = it;
                it++;
                dictionary.erase(it2);
                continue;
            }
        }
        it++;
    }
    return neighbors;
}

int getWordLadderLength(set<string> & dictionary, string startWord, string endWord){
    if(startWord == endWord) {
        return 0;
    }
    if (startWord.length() != endWord.length()){
        return -1;
    }
    if(dictionary.size() == 0) {
        return -1;
    }
    //add endWord if already not there
    set<string>::iterator it = dictionary.find(endWord);
    if(it == dictionary.end()){
        dictionary.insert(dictionary.end(),endWord);
    }
    
    //remove startWord if already there
    it = dictionary.find(startWord);
    if(it != dictionary.end()){
        dictionary.erase(it);
    }

    //populate the queue with start word
    queue<pair<string,int>> currentQueue;
    currentQueue.push(pair<string,int>(startWord,0));
    
    while (currentQueue.size() != 0){
        string qString = currentQueue.front().first;
        int qLength = currentQueue.front().second;
        currentQueue.pop();
        list<string> matches = findAndRemoveNeighbors(dictionary,qString);
        list<string>::iterator sIt = matches.begin();
        while (sIt != matches.end()){
            if ((*sIt) == endWord) {
                return qLength+1;
            } else {
                currentQueue.push(pair<string,int>(*sIt,qLength+1));
            }
            sIt++;
        }
    }
    return -1;
}

string getWordLadderLength2(set<string> & dictionary, string startWord, string endWord){
    
    string s;
    
    if(startWord == endWord) {
        return s;
    }
    if (startWord.length() != endWord.length()){
        return s;
    }
    if(dictionary.size() == 0) {
        return s;
    }
    //add endWord if already not there
    set<string>::iterator it = dictionary.find(endWord);
    if(it == dictionary.end()){
        dictionary.insert(dictionary.end(),endWord);
    }
    
    //remove startWord if already there
    it = dictionary.find(startWord);
    if(it != dictionary.end()){
        dictionary.erase(it);
    }

    //populate the queue with start word
    queue<pair<string,string>> currentQueue;
    currentQueue.push(pair<string,string>(startWord,startWord));
    
    while (currentQueue.size() != 0){
        string qString = currentQueue.front().first;
        string qChain = currentQueue.front().second;
        currentQueue.pop();
        list<string> matches = findAndRemoveNeighbors(dictionary,qString);
        list<string>::iterator sIt = matches.begin();
        while (sIt != matches.end()){
            if ((*sIt) == endWord) {
                return qChain+"->"+endWord;
            } else {
                currentQueue.push(pair<string,string>(*sIt,qChain+"->"+(*sIt)));
            }
            sIt++;
        }
    }
    return s;
}




int main(){
    set<string> dictionary;
    /*
    dictionary.insert(dictionary.end(),"hot");
    dictionary.insert(dictionary.end(),"dot");
    dictionary.insert(dictionary.end(),"dog");
    dictionary.insert(dictionary.end(),"lot");
    dictionary.insert(dictionary.end(),"log");
    string startWord = "hit";
    string endWord = "cog";
    */
    dictionary.insert(dictionary.end(),"poon");
    dictionary.insert(dictionary.end(),"plee");
    dictionary.insert(dictionary.end(),"same");
    dictionary.insert(dictionary.end(),"poie");
    dictionary.insert(dictionary.end(),"plea");
    dictionary.insert(dictionary.end(),"plie");
    dictionary.insert(dictionary.end(),"poin");
    string startWord = "toon";
    string endWord = "plea";
    //cout<<"The word ladder distance between "<<startWord<<" and "<<endWord<<" is: "<<getWordLadderLength(dictionary,startWord,endWord)<<endl;
    cout<<"The word ladder between "<<startWord<<" and "<<endWord<<" is: "<<getWordLadderLength2(dictionary,startWord,endWord);
    return 0;
}