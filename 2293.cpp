#include <iostream>

using namespace std;


int A[100]={};


int dp[2][100001]={};


void fill_dp(int N, int K){
    dp[0][0]=1;
    dp[1][0]=1;
    for(int i=0; i<N; i++){
        int coin = A[i];

        int cur=i%2, prev=(i+1)%2;
        for(int j=1; j<=K; j++){
            dp[cur][j]=0;
            for(int k=0; k*A[i]<=j; k++){
                dp[cur][j] += dp[prev][j-k*A[i]];
            } 
        }
    }
}

int main(){
    int N, K;
    cin>>N>>K;

    for(int i=0; i<N; i++)cin>>A[i];

    fill_dp(N, K);

    cout<<dp[(N+1)%2][K];
}