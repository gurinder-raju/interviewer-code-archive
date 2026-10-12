/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
Note: The input string may contain letters other than the parentheses ( and ). 
*/

#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

bool isParenthesesValid(string s){
    stack<char> c;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '('){
            //starting parentheses
            c.push('(');
        } else if (s[i] == ')'){
            //closing parentheses   
            if (!c.empty() && c.top() == '('){
                //opening and closing parentheses cancel each other out
                c.pop();
            } else {
                return false;
            }
        } else {
            //do nothing
        }
    }
    if (c.empty()) {
        //there should be no remaining opening parentheses in the stack
        return true;
    } 
    return false;
}

//collect every version of s with numOfRemovals parentheses removed, removing from startIndex onwards
void generateRemovals(string s, int startIndex, int numOfRemovals, set<string> & versions){
    if (numOfRemovals == 0){
        versions.insert(s);
        return;
    }
    for (int i = startIndex; i < s.length(); i++){
        if (s[i] == '(' || s[i] == ')'){
            generateRemovals(s.substr(0,i) + s.substr(i+1), i, numOfRemovals-1, versions);
        }
    }
}

vector<string> removeInvalidParentheses(string s, int numOfRemovals = 0) {
    //Assume that you can have at least one valid parentheses with numOfRemovals parentheses removed
    vector<string> returnVal;
    if (numOfRemovals > s.length()){
        return returnVal;
    }
    /* 
    Iterate to prepare all possible versions of s with numOfRemovals and check if it yields positive results
    */
    set<string> versions;
    generateRemovals(s, 0, numOfRemovals, versions);
    for (set<string>::iterator it = versions.begin(); it != versions.end(); it++){
        if (isParenthesesValid(*it)) {
            returnVal.insert(returnVal.end(),*it);
        }
    }
    if (!returnVal.empty()) {
        return returnVal;
    }
    return removeInvalidParentheses(s,numOfRemovals+1);
}

int main(){
    vector<string> results = removeInvalidParentheses("()())()");
    vector<string>::iterator it = results.begin();
    while (it != results.end()){
        cout<<*it<<endl;
        it++;
    }
    return 0;
}