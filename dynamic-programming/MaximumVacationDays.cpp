/*
This function returns the max vacation days possible starting in city with cityIndex starting in week = weekIndex

Flights is an N*N matrix where N is the number of cities.
Days is an N*K matrix where N is cities and K is number of vacation days in Kth week in that city
*/

using namespace std;
#include <iostream>
#include <vector>

int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days, int weekIndex = 0, int cityIndex = 0) {
    
    if (flights.size() == 0 || flights[0].size() == 0 || days.size() == 0 || days[0].size() == 0) {
        return 0;
    }
    
    int numOfCities = flights.size();
    int numOfWeeks = days[0].size();///numOfCities;

    if(weekIndex > numOfWeeks-1){
        return 0;
    }
    
    int maxVacation = 0;
    
    for (int i = 0; i < numOfCities; i++){
        if(i != cityIndex){
            if(flights[cityIndex][i] == 0) continue;
        }
        int currentMaxVacation = maxVacationDays(flights,days,weekIndex+1,i);
        currentMaxVacation += days[i][weekIndex];
        if (currentMaxVacation  > maxVacation){
            maxVacation = currentMaxVacation;
        }
        cout<<"Max Vacation Starting Week "<<weekIndex<<" in city : "<<cityIndex<<" is: "<<maxVacation<<endl;
    }
    
    return maxVacation;    
}

int main(){
    vector<vector<int>> flights = {{0,1,1},{1,0,1},{1,1,0}};
    vector<vector<int>> days = {{1,3,1},{6,0,3},{3,3,3}};
    vector<vector<int>> flights1 = {{0,0,0},{0,0,0},{0,0,0}};
    vector<vector<int>> days1 = {{1,1,1},{7,7,7},{7,7,7}};
    cout<<maxVacationDays(flights1,days1)<<endl;
    return 0;
}