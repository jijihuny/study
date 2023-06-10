#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    
    cin>>N>>M;

    int count=0;
    int coin[N+1];
    coin[N]=INT32_MAX;
    for(int i=0;i<N;i++){
        cin>>coin[i];
    }

    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            if(M/coin[j]==0){
                count+=M/coin[j-1];
                M = M%coin[j-1];
                break;
            }
        }
        if(M==0)break;
    }
    
    cout<<count;
}