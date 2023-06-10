#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;


vector<string> board;
vector<vector<vector<bool>>> visited;
typedef vector<int> node;

int bfs(){
    int maxRow = board.size();
    int maxCol = board[0].size();

    int rootRow = 0;
    int rootCol = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for(int row=0; row<maxRow; ++row){
        for(int col=0; col<maxCol; ++col){
            if(board[row][col]=='0'){
                rootRow = row;
                rootCol = col;
                break;
            }
        }
    }

    visited = vector<vector<vector<bool>>>(maxRow, vector<vector<bool>>(maxCol, vector<bool>(64, 0)));

    queue<node> q;

    q.push({rootRow, rootCol, 0, 0});//row, col, count, keys.

    visited[rootRow][rootCol][0] = true;

    while(!q.empty()){
        auto now = q.front();

        q.pop();

        auto row = now[0], col = now[1], count = now[2], curKeys = now[3];

        if(board[row][col]=='1')
            return count;


        for(int i=0; i<4; ++i){
            int nrow = row + dr[i], ncol = col + dc[i];

            int nextKeys = curKeys;

            if(nrow < 0 || nrow >= maxRow ||
                ncol < 0 || ncol >= maxCol)
                continue;

            if(board[nrow][ncol] == '#' || visited[nrow][ncol][curKeys])
                continue;

            if(('A' <= board[nrow][ncol] && board[nrow][ncol] <= 'F') &&
                !(curKeys & (1 << (board[nrow][ncol] - 'A'))))
                continue;

            if('a' <= board[nrow][ncol] && board[nrow][ncol] <= 'f')
                nextKeys |= (1 << (board[nrow][ncol] - 'a'));


            visited[nrow][ncol][nextKeys] = true;

            q.push({nrow, ncol, count+1, nextKeys});
        }

        
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N, M;

    cin>>N>>M;

    board = vector<string>(N, string());

    for(int i=0; i<N; ++i){
        cin>>board[i];
    }

    cout<<bfs();
}