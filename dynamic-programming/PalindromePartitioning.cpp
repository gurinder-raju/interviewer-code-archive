/*
Partition a string so that every substring in the partition is a palindrome.
Return all possible palindrome partitions.
*/

using namespace std;
#include <iostream>
#include <vector>

bool isPalindrome(string s){
    int j = s.length();
    if (j == 0) return true;
    int i = 0;
    j--;
    while(i <= j){
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

void insertStringInAllPartitions(string s, vector<vector<string>> & subpartitions, vector<vector<string>> & partitions){
    vector<vector<string>>::iterator it = subpartitions.begin();
    while (it != subpartitions.end()){
        (*it).insert((*it).begin(),s);
        it++;
    }
    it = subpartitions.begin();
    while (it != subpartitions.end()){
        partitions.insert(partitions.end(),*it);
        it++;
    }
}


vector<vector<string>> palindromePartitions(string s){
    vector<vector<string>> partitions;
    int stringLength = s.length();
    for(int i = 1; i <= stringLength; i++){
        string stringSoFar = s.substr(0,i);
        if(isPalindrome(stringSoFar)){
            if(i == stringLength){
                vector<string> s;
                s.insert(s.begin(),stringSoFar);
                partitions.insert(partitions.end(),s);
            } else {
                string remainingString = s.substr(i,stringLength-i);
                vector<vector<string>> subpartitions = palindromePartitions(remainingString);
                if(subpartitions.size() != 0){
                    insertStringInAllPartitions(stringSoFar,subpartitions,partitions);
                }
            }
        }
    }
    return partitions;
}

int main(){
    vector<vector<string>> partitions = palindromePartitions("ababb");
    vector<vector<string>>::iterator it = partitions.begin();
    while (it != partitions.end()){
        vector<string>::iterator it2 = (*it).begin();
        while (it2 != (*it).end()){
            cout<<(*it2)<< "  ";
            it2++;
        }
        it++;
        cout<<endl;
    }
    return 0;
}