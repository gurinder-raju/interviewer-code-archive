/*
Print all the permutations of a string. Duplicates are allowed.
*/

#include <iostream>
using namespace std;

void printPermutations(string str, string prefix="") {
    int length = str.length();
    if (length == 0) {
       cout<<prefix<<endl;
       return;
    }
    for (int i = 0; i < length;i++) {
        char temp = str[0];
        str[0] = str[i];
        str[i] = temp;
        printPermutations(str.substr(1), prefix+str[0]);
        str[i] = str[0];
        str[0] = temp;
    }
}

int main(){
    string str = "1635";
    printPermutations(str);
    return 0;
}