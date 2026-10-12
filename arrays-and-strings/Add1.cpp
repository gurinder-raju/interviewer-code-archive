/*
Add one to a non-negative integer stored as a vector of digits, most significant
digit first. For example, 999 becomes 1000.
*/

#include <iostream>
#include <vector>
using namespace std;

void addOne(vector<int> & base){
    for (int i = base.size()-1; i >= 0; i--){
        if(base[i] == 9){
            base[i] = 0;
        } else {
            base[i] = base[i]+1;
            return;
        }
    }
    base[0] = 1;
    base.push_back(0);
    return;
}

void printBigInteger(vector<int> & base){
    auto it = base.begin();
    while (it != base.end()){
        cout<<(*it);
        it++;
    }
    cout<<endl;
}

int main(){
    vector<int> base;
    base.push_back(9);
    base.push_back(9);
    base.push_back(9);
    addOne(base);
    printBigInteger(base);
    return 0;
}