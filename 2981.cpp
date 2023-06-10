#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef unsigned int ui;

ui arr[100];

set<int> answer;


void solution(int N){
    sort(arr, arr+N);
    
}

int main(){
    int N;
    cin>>N;

    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    solution(N);

    for(auto i : answer)cout<<i<<" ";
}