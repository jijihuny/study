#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


queue<pair<int, int>> q;
int binary_field[100][100]={};
int field[100][100]={};
bool visited[100][100]={};

int N, M;
int drow[]={-1, 0, 1, 0};
int dcol[]={0, -1, 0, 1};


void dfs(int row, int col){

    
    visited[row][col]=1;

    if(binary_field[row][col])return;
    field[row][col]=binary_field[row][col];

    for(int i=0; i<4; ++i){
        int nrow=row+drow[i], ncol=col+dcol[i];

        if(nrow<0 || nrow>N || ncol<0 || ncol>M || visited[nrow][ncol])
            continue;

        dfs(nrow, ncol);
    }
}

void find_enclosed(){
    for(auto row : field){
        fill_n(row, M, INT32_MAX);
    }

    dfs(0, 0);

    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<M; ++j){
    //         if(binary_field[i][j])field[i][j]=1;
    //     }
    // }
}

void bfs(int row_start, int col_start){
    for(auto row : visited){
        fill_n(row, M, 0);
    }

    q.push({row_start, col_start});

    int around[4]={};
    while(!q.empty()){
        int row = q.front().first, col = q.front().second;
        q.pop();
        if(visited[row][col])continue;

        visited[row][col]=true;

        for(int i=0; i<4; ++i){
            int nrow = row + drow[i], ncol = col + dcol[i];

            if(nrow<0 || nrow>=N || ncol<0 || 
            ncol>=M || visited[nrow][ncol])
                continue;

            q.push({nrow, ncol});
        }

        if(field[row][col]==0)continue;

        for(int i=0; i<4; ++i){
            int nrow = row + drow[i], ncol = col + dcol[i];

            around[i] = field[nrow][ncol];
        }
        sort(around, around+4);
        if(binary_field[row][col]){
            field[row][col]=around[1]+1;
        }
        else field[row][col]=around[0];
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;

    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>binary_field[i][j];
        }
    }

    find_enclosed();
    
    bfs(N-1, M-1);

    
    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<M; ++j){
    //         cout<<field[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    bfs(0, 0);
    
    bfs(N-1, 0);

    bfs(0, M-1);

    

    int max_n = 0;

    // for(int i=0; i<N; ++i){
    //     for(int j=0; j<M; ++j){
    //         cout<<field[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            max_n = max_n<field[i][j]?field[i][j]:max_n;
        }
    }

    cout<<max_n;
}