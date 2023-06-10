#include <iostream>


using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;

    cin>>N>>M>>K;

    bool rec_board[N+1][M+1]={};

    char temp;
    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            cin>>temp;
            if(temp=='W')rec_board[i][j]=1;
        }
    }

    int w[N+1][M+1]={};
    int b[N+1][M+1]={};

    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1];
            w[i][j] = w[i-1][j] + w[i][j-1] - w[i-1][j-1];
            if((i+j)%2==0){
                if(rec_board[i][j]==0)w[i][j]++;
                else b[i][j]++;    
            }
            else{
                if(rec_board[i][j]==0)b[i][j]++;
                else w[i][j]++;
            }
        }
    }



    int min_cost=INT32_MAX;

    int c_N = N - K + 1, c_M = M - K + 1;
    int w_temp=0, b_temp=0;
    for(int i=0; i<c_N; i++){
        for(int j=0; j<c_M; j++){
            w_temp = w[K+i][K+j] - w[K+i][j] - w[i][K+j] + w[i][j];
            b_temp = b[K+i][K+j] - b[K+i][j] - b[i][K+j] + b[i][j];

            min_cost = min(min(w_temp, b_temp), min_cost);
            
        }
    }
    
    cout<<min_cost;
}