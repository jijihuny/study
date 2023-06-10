#include <string>
#include <vector>
#include <set>
using namespace std;


set<pair<int, int>> board;
set<pair<int, int>> visited;

template<typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &a, const pair<T1, T2> &b){
    return pair<T1, T2>{a.first+b.first, a.second+b.second};
}

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int max_x=0, min_x=0, max_y=0, min_y=0;

void fill_board(vector<int> arrows){
    board.insert({{0, 0}});
    auto prev = pair<int, int>{0, 0};
    
    
    for(auto &arrow : arrows){
        for(int i=0; i<3; ++i){
            prev = prev + pair<int, int>{dx[arrow], dy[arrow]};
            max_x = max_x<prev.first?prev.first:max_x;
            min_x = min_x>prev.first?prev.first:min_x;
            max_y = max_y<prev.second?prev.second:max_y;
            min_y = min_y>prev.second?prev.second:min_y;

            if(board.find(prev)!=board.end())continue;
            board.insert(prev);
        }
    }
}



int vx[]={-1, 1, 0, 0};
int vy[]={0, 0, -1, 1};

bool dfs(int x, int y){
    if(x<min_x || x>max_x || y<min_y || y>max_y)return false;

    if(board.find({x, y})!=board.end())return true;


    visited.insert({x, y});
    
    bool ret_val = true;

    for(int i=0; i<4; ++i){
        int nx=x+vx[i], ny=y+vy[i];

        if(visited.find({nx, ny})!=visited.end())continue;

        ret_val &= dfs(nx, ny);
    }

    return ret_val;
}

void solve(int &answer){
    for(int x=min_x; x<=max_x; ++x){
        for(int y=min_y; y<=max_y; ++y){
            if(board.find({x, y})!=board.end() || visited.find({x, y})!=visited.end())continue;

            if(dfs(x, y))++answer;
        }
    }
}

int solution(vector<int> arrows) {
    int answer = 0;
    fill_board(arrows);

    solve(answer);
    
    return answer;
}