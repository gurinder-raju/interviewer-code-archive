/*
Given a string and a dictionary. 
Bold all words in the dictionary in that string
For two overlapping words, bold the combined string
For two adjoining bolds, coalesce
*/

using namespace std;
#include <iostream>
#include <vector>
#include <list>

bool containsWord(vector<string> & dictionary, string inputString){
    vector<string>::iterator it = dictionary.begin();
    while (it != dictionary.end()){
        if (*it == inputString) return true;
        it++;
    }
    return false;
}

void addOrMerge(list<pair<int,int>> & tagBoundaries, pair<int,int> boundary){
    if(tagBoundaries.size() == 0) {
        tagBoundaries.push_back(boundary);
        //cout<<"Added Boundary: "<<boundary.first<<"->"<<boundary.second<<endl;
    }
    else {
        int lastElementStart = (tagBoundaries.back()).first;
        int lastElementEnd = (tagBoundaries.back()).second;
        //cout<<lastElementStart<<lastElementEnd<<endl;
        if(boundary.first >= lastElementStart && boundary.first <= lastElementEnd){
            //delete last element and insert new one
            tagBoundaries.pop_back();
            lastElementEnd = max(lastElementEnd,boundary.second);
            tagBoundaries.push_back(pair<int,int>(lastElementStart, lastElementEnd));
            //cout<<"Updated Boundary: "<<lastElementStart<<"->"<<lastElementEnd<<endl;
        } else {
            tagBoundaries.push_back(boundary);
            //cout<<"Added Boundary: "<<boundary.first<<"->"<<boundary.second<<endl;
        }
    }
}

void putBoldTags(vector<string> dictionary, string inputString){

    int startIndex = 0;
    int stringLength = 0;
    int inputStringLength = inputString.length();
    string outputString;

    //Merged tag boundaries
    list<pair<int,int>> tagBoundaries;
    
    //Find the longest word in the dictionary
    int longestWordLength = 0;
    vector<string>::iterator it = dictionary.begin();
    while (it != dictionary.end()){
        int currLength = (*it).length();
        if (currLength > longestWordLength) {
            longestWordLength = currLength;
        }
        it++;
    }
    //cout<<"Longest Word Length is: "<<longestWordLength<<endl;

    while (startIndex < inputStringLength) {
        if(startIndex + stringLength > inputStringLength) {
            startIndex++;
            stringLength = 1;
            continue;
        }
        string currString = inputString.substr(startIndex,stringLength);
        if (containsWord(dictionary,currString)){
            //cout<<"Found: "<<currString<<endl;
            addOrMerge(tagBoundaries,pair<int,int>(startIndex,startIndex+stringLength));
        }
        //no more word possible
        if(stringLength == longestWordLength) {
            startIndex++;
            stringLength=1;
        } else {
            stringLength++;
        }
    }
    
    //process non overlapping, non-adjacent boundaries
    int lastIndex=0;
    list<pair<int,int>>::iterator bIt = tagBoundaries.begin();
    while (bIt != tagBoundaries.end()){
        int i = (*bIt).first;
        int j = (*bIt).second;
        cout<<inputString.substr(lastIndex,i-lastIndex);
        cout<<"<b>";
        cout<<inputString.substr(i,j-i);
        cout<<"</b>";
        lastIndex = j;
        bIt++;
    }
    cout<<inputString.substr(lastIndex,inputStringLength-lastIndex);
    cout<<endl;
}


int main(){
    string s("aaabbcc");
    vector<string> dictionary;
    dictionary.push_back("aaa");
    dictionary.push_back("aab");
    dictionary.push_back("bc");
    putBoldTags(dictionary,s);
}
