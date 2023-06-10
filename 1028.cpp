#include <iostream>
#include <vector>

using namespace std;


vector<vector<bool>> mine;

vector<vector<bool>> visited;

vector<vector<vector<int>>> lengthToEndPoints;


int dfs(const int &row, const int &col, const int &dir){
    static int dr[] = {1, 1, -1, -1};
    static int dc[] = {1, -1, 1, -1};
    static int max_row = mine.size() - 1;
    static int max_col = mine.front().size() - 1;
    
    if(row < 0 || row > max_row || col < 0 || col > max_col || !mine[row][col]){
        return 0;
    }

    int nrow = row + dr[dir];
    int ncol = col + dc[dir];

    lengthToEndPoints[row][col][dir] = 
        1 + (lengthToEndPoints[nrow][ncol][dir]!=0) ?
        lengthToEndPoints[nrow][ncol][dir] :
        dfs(nrow, ncol, dir);

    return lengthToEndPoints[row][col][dir];
}

void fillLength(){
    int max_row = mine.size();
    int max_col = mine.front().size();
    for(int dir=0; dir<4; ++dir){
        for(int row = 0; row < max_row; ++row){
            for(int col = 0; col < max_col; ++col){
                dfs(row, col, dir);
            }
        }
    }
}

int solve(){
    int max = 0;

    int max_row = mine.size();
    int max_col = mine.front().size();

    for(int row = 0; row < max_row; ++row){
        for(int col = 0; col < max_col; ++col){

        }
    }
}