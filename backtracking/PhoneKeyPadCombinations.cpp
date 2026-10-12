/*
Given a string of digits, return every letter combination they could spell on a
phone keypad (2 = abc, 3 = def, ... 9 = wxyz).
*/

using namespace std;
#include <iostream>
#include <vector>
#include <map>


class phonePad {
    private: 
        static phonePad * instance;
        phonePad(){
            phoneDigitLetterMapping.insert(pair<char,string>('1',""));
            phoneDigitLetterMapping.insert(pair<char,string>('2',"abc"));
            phoneDigitLetterMapping.insert(pair<char,string>('3',"def"));
            phoneDigitLetterMapping.insert(pair<char,string>('4',"ghi"));
            phoneDigitLetterMapping.insert(pair<char,string>('5',"jkl"));
            phoneDigitLetterMapping.insert(pair<char,string>('6',"mno"));
            phoneDigitLetterMapping.insert(pair<char,string>('7',"pqrs"));
            phoneDigitLetterMapping.insert(pair<char,string>('8',"tuv"));
            phoneDigitLetterMapping.insert(pair<char,string>('9',"wxyz"));
            phoneDigitLetterMapping.insert(pair<char,string>('0',""));
        }
    public:
        static phonePad * getInstance() {
            if(instance == NULL) {
                instance = new phonePad;
            }
            return instance;
        }
        map<char,string> phoneDigitLetterMapping;
        ~phonePad() {
            delete instance;
        }
};

phonePad * phonePad::instance = NULL;

vector<string> letterCombinations(string digits) {
    
        vector<string> returnValue;
        if (digits.length() == 0) {
            returnValue.insert(returnValue.begin(),"");
            return returnValue;
        }

        vector<string> subCombinations = letterCombinations(digits.substr(1,digits.length()-1));

        char digit = digits[0];
        string letterMapping = phonePad::getInstance()->phoneDigitLetterMapping[digit];
    
        for (int i = 0; i < subCombinations.size(); i++) {
            string str = subCombinations[i];
            for (int j = letterMapping.length()-1; j >= 0; j--){
                returnValue.insert(returnValue.begin(),letterMapping[j]+str);
            }
        }
        return returnValue;
}

int main(){
    vector<string> combinations = letterCombinations("23");
    vector<string>::iterator it = combinations.begin();
    while (it != combinations.end()){
        cout<<*it<<endl;
        it++;
    }
    return 0;
}