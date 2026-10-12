/*
Given digits, figure out the number of ways it can be decoded
*/

#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

class DigitsToCodeMapping {
    public:
        static unordered_map <string,string> mapping;
        DigitsToCodeMapping(){
            mapping.insert(mapping.begin(),pair<string,string>("1","A"));
            mapping.insert(mapping.begin(),pair<string,string>("2","B"));
            mapping.insert(mapping.begin(),pair<string,string>("3","C"));
            mapping.insert(mapping.begin(),pair<string,string>("4","D"));
            mapping.insert(mapping.begin(),pair<string,string>("5","E"));
            mapping.insert(mapping.begin(),pair<string,string>("6","F"));
            mapping.insert(mapping.begin(),pair<string,string>("7","G"));
            mapping.insert(mapping.begin(),pair<string,string>("8","H"));
            mapping.insert(mapping.begin(),pair<string,string>("9","I"));
            mapping.insert(mapping.begin(),pair<string,string>("10","J"));
            mapping.insert(mapping.begin(),pair<string,string>("11","K"));
            mapping.insert(mapping.begin(),pair<string,string>("12","L"));
            mapping.insert(mapping.begin(),pair<string,string>("13","M"));
            mapping.insert(mapping.begin(),pair<string,string>("14","N"));
            mapping.insert(mapping.begin(),pair<string,string>("15","O"));
            mapping.insert(mapping.begin(),pair<string,string>("16","P"));
            mapping.insert(mapping.begin(),pair<string,string>("17","Q"));
            mapping.insert(mapping.begin(),pair<string,string>("18","R"));
            mapping.insert(mapping.begin(),pair<string,string>("19","S"));
            mapping.insert(mapping.begin(),pair<string,string>("20","T"));
            mapping.insert(mapping.begin(),pair<string,string>("21","U"));
            mapping.insert(mapping.begin(),pair<string,string>("22","V"));
            mapping.insert(mapping.begin(),pair<string,string>("23","W"));
            mapping.insert(mapping.begin(),pair<string,string>("24","X"));
            mapping.insert(mapping.begin(),pair<string,string>("25","Y"));
            mapping.insert(mapping.begin(),pair<string,string>("26","Z"));
        }
        static bool isThereCodeForDigits(string digits){
            static unordered_map <string,string> mapping;
            mapping.insert(mapping.begin(),pair<string,string>("1","A"));
            mapping.insert(mapping.begin(),pair<string,string>("2","B"));
            mapping.insert(mapping.begin(),pair<string,string>("3","C"));
            mapping.insert(mapping.begin(),pair<string,string>("4","D"));
            mapping.insert(mapping.begin(),pair<string,string>("5","E"));
            mapping.insert(mapping.begin(),pair<string,string>("6","F"));
            mapping.insert(mapping.begin(),pair<string,string>("7","G"));
            mapping.insert(mapping.begin(),pair<string,string>("8","H"));
            mapping.insert(mapping.begin(),pair<string,string>("9","I"));
            mapping.insert(mapping.begin(),pair<string,string>("10","J"));
            mapping.insert(mapping.begin(),pair<string,string>("11","K"));
            mapping.insert(mapping.begin(),pair<string,string>("12","L"));
            mapping.insert(mapping.begin(),pair<string,string>("13","M"));
            mapping.insert(mapping.begin(),pair<string,string>("14","N"));
            mapping.insert(mapping.begin(),pair<string,string>("15","O"));
            mapping.insert(mapping.begin(),pair<string,string>("16","P"));
            mapping.insert(mapping.begin(),pair<string,string>("17","Q"));
            mapping.insert(mapping.begin(),pair<string,string>("18","R"));
            mapping.insert(mapping.begin(),pair<string,string>("19","S"));
            mapping.insert(mapping.begin(),pair<string,string>("20","T"));
            mapping.insert(mapping.begin(),pair<string,string>("21","U"));
            mapping.insert(mapping.begin(),pair<string,string>("22","V"));
            mapping.insert(mapping.begin(),pair<string,string>("23","W"));
            mapping.insert(mapping.begin(),pair<string,string>("24","X"));
            mapping.insert(mapping.begin(),pair<string,string>("25","Y"));
            mapping.insert(mapping.begin(),pair<string,string>("26","Z"));
            unordered_map <string,string>::iterator it = mapping.find(digits);
            if (it == mapping.end()) {
                return false;
            }
            return true;
        }
};

int decodeDigits(string digits){
    
    int digitsLength = digits.length();
    
    if (digits.length() == 0) return 1;
    
    if (digits.length() == 1) {
        if (DigitsToCodeMapping::isThereCodeForDigits(digits)) {
            return 1;
        } 
        return 0;
    } 
    
    string firstTwoSubDigits = digits.substr(0,2);
    string firstSubDigit = digits.substr(0,1);
    
    int numberofWaysAfterTwoSubDigits = 0;
    int numberofWaysAfterFirstSubdigit = 0;
    
    //T(n) = T(n-1), if n means something + T(n-2), n+n-1 mean something

    if(DigitsToCodeMapping::isThereCodeForDigits(firstSubDigit)){
        numberofWaysAfterFirstSubdigit += decodeDigits(digits.substr(1,digitsLength-1));
    }
    if(DigitsToCodeMapping::isThereCodeForDigits(firstTwoSubDigits)){
        numberofWaysAfterTwoSubDigits += decodeDigits(digits.substr(2,digitsLength-2));
    }
    return numberofWaysAfterFirstSubdigit + numberofWaysAfterTwoSubDigits;
}


int main(){
    string digits = "1234";
    cout<<"Number of ways to decode: "<<digits<<" is: "<<decodeDigits(digits)<<endl;
}