#include <iostream>

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

typedef vector<vector<vector<long long>>> Mat_100x10x10;


Mat_100x10x10 dp(101, vector<vector<long long>>(10, vector<long long>(10, 0)));




void fillDp(){
    for(int len=2; len<101; ++len){
        for(int start=0; start<10; ++start){
            for(int end=start+1; end<10; ++end){
                if(len==2 && abs(start-end)==1){
                    dp[len][start][end] = 1;
                    continue;
                }

                dp[len][start][end] = ((start==0 ? 0 : dp[len-1][start-1][end]) +
                                      dp[len-1][start+1][end] +
                                      (end==9 ? 0 : dp[len-1][start][end+1]) +
                                      dp[len-1][start][end-1])% 1000000000;
            }
        }
    }
}

int answer;

void solve(int N){
    int start=2, end=N;
    long long sum = dp[N][0][9];
    for(;start<N-1; ++start){
        for(end=N; end>start+9; --end){
            sum += dp[end-start+1][0][9] * 2 +
                   accumulate(dp[start][0].begin(), dp[start][0].end(), 0) +
                   sum(dp[N-end+1][9])
        }
    }
}