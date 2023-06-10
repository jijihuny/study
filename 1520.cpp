#include <iostream>
#include <algorithm>
using namespace std;

int dp[500][500];
int board[500][500]={};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int N=499, M=499;
int dfs(int row, int col, int px, int py){
    if(dp[row][col]>=0)return dp[row][col];
    if(row==N&&col==M)return 1;
    
    dp[row][col]=0;

    
    
    for(int i=0; i<4; i++){
        int nx=row+dx[i];
        int ny=col+dy[i];
        if(nx==px&&ny==py)continue;
        if(nx<0||ny<0||nx>N||ny>M)continue;


        if(board[nx][ny]<board[row][col])
        dp[row][col]+=dfs(nx, ny, row, col);
    }

    return dp[row][col];
}

int main(){
    fill(dp[0], dp[499]+500, -1);

    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>board[i][j];
        }
    }
    N--; M--;

    dfs(0, 0, 0, 0);

    cout<<dp[0][0];
}