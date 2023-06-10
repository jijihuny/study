#include <iostream>
#include <cmath>

using namespace std;

double first = (1.0 + sqrt(5.0))/2.0;
double second = (1.0 - sqrt(5.0))/2.0;

double power_numbers[100][2];



void fill_pn(){
    power_numbers[1][0]=first;
    power_numbers[1][1]=second;
    for(int i=2; i<100; i++){
        power_numbers[i][0] = power_numbers[i-1][0]*power_numbers[i-1][0];
        power_numbers[i][1] = power_numbers[i-1][1]*power_numbers[i-1][1];
    }

    for(int i=1; i<100; i++){
        cout<<power_numbers[i][0]<<" ";
    }
    for(int i=1; i<100; i++){
        cout<<power_numbers[i][1]<<" ";
    }
}


int main(){
    fill_pn();
}