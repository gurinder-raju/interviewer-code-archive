
using namespace std;
#include <iostream>


int findChar(char c, string s){
    int sLength = s.length();
    for (int i = 0; i < sLength; i++){
        if (s[i] == c) return i;
    }
    return -1;
}



int findLCS(string s1, string s2){
    
    int s1Length = s1.length();
    int s2Length = s2.length();
    if(s1Length == 0 || s2Length == 0) {
        return 0;
    }
    
    int longestLCS = 0;
    
    for (int i = 0; i < s1Length; i++){
        int currLCS = 0;
        char c = s1[i];
        int cIndex = findChar(c,s2);
        if (cIndex != -1){
            currLCS++;
            currLCS += findLCS(s1.substr(i+1,s1Length-i-1),s2.substr(cIndex+1,s2Length-cIndex-1));
            if (currLCS > longestLCS){
                longestLCS = currLCS;
            }
        }
    }
    
    return longestLCS;
}

//with memoization
template <int rows, int cols>
int findLCS3(string & s1, int i1, string & s2, int i2, int (&memoArray) [rows][cols]){

    int s1Length = s1.length();
    int s2Length = s2.length();
    if( i1 > s1Length-1 || i2 > s2Length-1) {
        return 0;
    }
    
    int longestLCS = memoArray[i1][i2];
    if (longestLCS != -1) return longestLCS;
    longestLCS = 0;
    
    for (int i = i1; i < s1Length; i++){
        int currLCS = 0;
        char c = s1[i];
        int cIndex = findChar(c,s2.substr(i2,s2Length-i2));
        if (cIndex != -1){
            currLCS++;
            currLCS += findLCS3(s1,i+1,s2,i2+cIndex+1,memoArray);
            if (currLCS > longestLCS){
                longestLCS = currLCS;
            }
        }
    }
    
    memoArray[i1][i2] = longestLCS;
    return longestLCS;
}

int findLCS2(string s1,string s2){
    int rows = s1.length();
    int cols = s2.length();
    
    int memoArray [6][6] = {{-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1}};
                            
    int returnValue =  findLCS3(s1,0,s2,0,memoArray);
    /*
    for (int i = 0; i < 6 ; i++){
        for (int j = 0; j < 6 ; j ++){
            cout<<""<<memoArray[i][j];
        }
        cout<<endl;
    }
    */
    return returnValue;
}

int main(){
    /*
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";*/
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";

    int lcs = findLCS(s1,s2);
    int lcs2 = findLCS2(s1,s2);
    cout<<"LCS between: "<<s1<<" & "<<s2<<" is: "<<lcs<<endl;
    cout<<"LCS2 between: "<<s1<<" & "<<s2<<" is: "<<lcs2<<endl;
}