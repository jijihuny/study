#include <complex>
#include <iostream>

#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<complex<float>> coordinates;

vector<vector<bool>> board(5, vector<bool>(5, 0));

vector<bool> visited(25, 0);

bool dfs(int r, int c, bool init){//check all elements are connected.
    static int i = 0;
    static const int dr[] = {-1, 1, 0, 0};
    static const int dc[] = {0, 0, -1, 1};
    
    if(init){i=0;visited.assign(25, 0);}

    visited[r*5+c]=1;
    cout<<i<<" row"<<r<<"col"<<c<<"\n";
    if(++i==coordinates.size())return true;

    for(int t = 0; t<4; ++t){
        auto nr = r + dr[t], nc = c + dc[t];

        if(nr < 0 || nr >=5 || nc < 0 || nc >= 5)continue;
        if(visited[nr*5+nc] || !board[nr][nc])continue;

        if(dfs(nr, nc, false)) return true;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // char temp;

    
    // for(int i=0; i<5; ++i){
    //     for(int j=0; j<5; ++j){
    //         cin>>temp;
    //         if(temp=='*'){
    //             coordinates.push_back({(float)i, (float)j});
    //             board[i][j]=1;
    //         }
    //     }
    // }
    vector<string> temp(5, string());
    for(int i=0; i<5; ++i)cin>>temp[i];

    for(int r=0; r<5; ++r){
        for(int c=0; c<5; ++c){
            if(temp[r].at(c)=='*'){
                coordinates.push_back(complex<float>{r, c});
                board[r][c] = 1;
            }
        }
    }

    complex<float> center = {0, 0};

    for(auto elem : coordinates){
        center += elem;
    }

    center /= complex<float>{(float)coordinates.size(), 0};

    auto cmp = [&center](const complex<float> &a, const complex<float> &b){
        return abs(a - center) < abs(b - center);
    };

    int t = 0;

    while(!dfs(coordinates[0].real(), coordinates[0].imag(), true)){
        
        

        
        
        sort(coordinates.begin(), coordinates.end(), cmp);

        auto &&far = coordinates.back() - center;

        board[coordinates.back().real()][coordinates.back().imag()] = 0;

        center -= coordinates.back() / complex<float>{(float)coordinates.size(), 0};

        if(abs(far.real()) < abs(far.imag())){

            coordinates.back() -= complex<float>{0, (float)copysign(1.0, far.imag())};

        }
        else{

            coordinates.back() -= complex<float>{(float)copysign(1.0, far.real()), 0};

        }

        for(auto elem : coordinates)cout<<elem<<" ";
        cout<<"\n";

        for(auto row : board){
            for(auto col : row)cout<<col<<" ";
        cout<<"\n";}
        if(board[coordinates.back().real()][coordinates.back().imag()])break;
        board[coordinates.back().real()][coordinates.back().imag()] = 1;

        center += coordinates.back() / complex<float>{(float)coordinates.size(), 0};

        t++;
    }
    

    cout<<t;
}