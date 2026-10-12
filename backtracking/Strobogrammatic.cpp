/*
Strobogrammatic numbers: find all numbers of length n that look the same when rotated
180 degrees (upside down), such as 69, 818 and 1001.
*/

using namespace std;
#include <iostream>
#include <unordered_set>

unordered_set <string> findStrobogrammatic(int n){
    unordered_set<string> returnVal;
    if (n < 0){
        return returnVal;
    }
    if (n == 0){
        returnVal.insert(returnVal.begin(),"");
        return returnVal;
    }
    //get all possible for n-1
    if (n%2 != 0){
        unordered_set<string> oneSmaller = findStrobogrammatic(n-1);
        for(unordered_set<string>::iterator it = oneSmaller.begin(); it != oneSmaller.end();it++) {
            string currentString = *it;
            string firstHalf = currentString.substr(0,currentString.length()/2);
            string secondHalf = currentString.substr(currentString.length()/2,currentString.length()/2);
            returnVal.insert(firstHalf+"0"+secondHalf);
            returnVal.insert(firstHalf+"1"+secondHalf);
            returnVal.insert(firstHalf+"8"+secondHalf);
        }
    }

    //get all possible for n-2
    unordered_set<string> twoSmaller = findStrobogrammatic(n-2);
    for(unordered_set<string>::iterator it = twoSmaller.begin(); it != twoSmaller.end();it++) {
        string currentString = *it;
        returnVal.insert("6"+currentString+"9");
        returnVal.insert("9"+currentString+"6");
        returnVal.insert("1"+currentString+"1");
        returnVal.insert("8"+currentString+"8");
        if(n%2 == 0){
            string firstHalf = currentString.substr(0,currentString.length()/2);
            string secondHalf = currentString.substr(currentString.length()/2,currentString.length()/2);
            if (n > 2){
                returnVal.insert(firstHalf+"00"+secondHalf);
            }
            returnVal.insert(firstHalf+"11"+secondHalf);
            returnVal.insert(firstHalf+"88"+secondHalf);
            returnVal.insert(firstHalf+"69"+secondHalf);
            returnVal.insert(firstHalf+"96"+secondHalf);
        }
    }
    return returnVal;
}

int main(){
    unordered_set<string> returnVal = findStrobogrammatic(7);
    unordered_set<string>::iterator it = returnVal.begin();
    while(it != returnVal.end()){
        cout<<*it<<endl;
        it++;
    }
    return 0;
}