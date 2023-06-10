#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int N;

vector<int> answer(10, 0);


void solve(){
    for(int i=0; i<11; ++i){
        if(i!=10){
            for(auto &elem : answer){
                elem += (N /(int)pow(10, i)) * (int)pow(10, i);
            }

            answer[0] -= (int)pow(10, i);

            

        }
    }
}