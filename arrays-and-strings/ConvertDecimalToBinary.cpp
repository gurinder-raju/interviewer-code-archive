/*
Convert a non-negative decimal integer to its binary representation as a string.
*/

#include <iostream>
using namespace std;

string addOneBinary(string s){
    string returnValue(s);
    for (int i = s.length(); i > 0 ; i--){
        if (s[i-1] == '0'){
            returnValue[i-1] = '1';
            return returnValue;
        } else {
            returnValue[i-1] = '0';
            if(i == 1) {
                returnValue = "1"+returnValue;
            }
        }
    }
    return returnValue;
}

string convertDecimaltoBinary(int decimal){
    string returnValue;
    if (decimal <= 1) {
        return decimal == 1 ? "1" : "0";
    }
    returnValue = convertDecimaltoBinary(decimal/2)+"0";
    bool isOdd = (decimal%2 != 0);
    
    if (isOdd) {
        returnValue = addOneBinary(returnValue);
    } 
    return returnValue;
}


int main(){
    cout<<convertDecimaltoBinary(756)<<endl;
    //1011110100
    cout<<convertDecimaltoBinary(323)<<endl;
    //101000011
    cout<<convertDecimaltoBinary(5)<<endl;
    cout<<convertDecimaltoBinary(6)<<endl;
    cout<<convertDecimaltoBinary(7)<<endl;
    cout<<convertDecimaltoBinary(1024)<<endl;
    cout<<convertDecimaltoBinary(0)<<endl;
}