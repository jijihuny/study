#include <iostream>

#include <vector>
using namespace std;

int board[9][9];


vector<pair<int, int>> undercover;

void fill_under(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(!board[i][j])undercover.push_back({i, j});
        }
    }
}

bool dfs(vector<pair<int, int>>::iterator now){
    if(now==undercover.end())return true;

    int row=now->first, col=now->second;

    for(int n=1; n<=9; ++n){
        board[row][col]=n;

        bool flag=false;
        for(int idx=0; idx<9; ++idx){
            if(idx!=row&&board[row][col]==board[idx][col])
                break;
            else if(idx!=col&&board[row][col]==board[row][idx])
                break;
            else if(row!=(row/3)*3+idx/3&&col!=(col/3)*3+idx%3&&
                    board[row][col]==board[(row/3)*3+idx/3][(col/3)*3+idx%3])
                break;
            
            if(idx==8)flag=true;
        }

        
        if(flag){
            if(!dfs(now+1))continue;
            else return true;
        }
    }

    board[row][col]=0;
    return false;
}


int main(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>board[i][j];
        }
    }

    fill_under();
    dfs(undercover.begin());

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}