/*
Optimal strategy for a game: coins are laid out in a row and two players take turns
picking a coin from either end. Find the maximum amount the first player can win
if both players play optimally.
*/

#include <iostream>
using namespace std;

template <int rows>
int findSum(int (&coins)[rows], int startIndex, int endIndex){
    if (startIndex > endIndex) return 0;
    return coins[startIndex] + findSum(coins, startIndex+1, endIndex);
}

template <int rows>
int findMaxWinningSum(int (&coins)[rows], int startIndex=0, int endIndex = rows-1){
    if (startIndex == endIndex){
        //last remaining coin for player 2
        return coins[startIndex];
    } else if (startIndex == endIndex - 1){
        //two coins remaining. last decision by player 1.
        if (coins[startIndex] > coins[endIndex]) {
            return coins[startIndex];
        } else {
            return coins[endIndex];
        }
    } else {
        int coinSum = findSum(coins,startIndex,endIndex);
        int startMax = coinSum - findMaxWinningSum(coins,startIndex+1,endIndex);
        int endMax = coinSum - findMaxWinningSum(coins,startIndex,endIndex-1);
        if (startMax > endMax){
            return startMax;
        } else {
            return endMax;
        }
    }
}


int main(){
    int coins1[] = {1,2,6,20,90,3,2,7};
    int coins2[] = {5,3,7,10};
    int coins3[] = {8,15,3,7};
    int coins4[] = {20, 30, 2, 2, 2, 10};
    cout << findMaxWinningSum(coins4) << endl;
    return 0;
}