#include <vector>
#include <iostream>

using namespace std;


class Solver{
    vector<vector<int>> pentagon;

    vector<vector<int>> leftToRight;
    vector<bool> visited;
    vector<int> leftFromRight;
    int W;
    int N;

    public:
    Solver(vector<vector<int>> &pentagon, int W, int N):
           pentagon{move(pentagon)}, W{W}, N{N}
           {
            visited = vector<bool>(N*2+1, 0);
            leftFromRight = vector<int>(N*2+1, 0);

            leftToRight = vector<vector<int>>(N*2 + 1, vector<int>());

            this->initLeftToRightArr();
           }

    int getN(){return N;}

    void initLeftToRightArr(){
        int di[] = {0, 0, 1};
        int dj[] = {-1, 1, 0};
        for(int i=0; i<2; ++i){
            for(int j=0; j<N; ++j){
                for(int k=0; k<3; ++k){
                    int ni = (i + di[k]) % 2;
                    int nj = (j + dj[k] + N) % N;
                    if(pentagon[i][j]+pentagon[ni][nj]<=W){
                        leftToRight[i*N + j + 1].push_back(ni * N + nj + 1);
                    }
                }
            }
        }
    }

    bool dfs(int node){
        //test
        visited[node] = true;

        for(auto right : leftToRight[node]){
            if(visited[right])continue;
            visited[right] = true;

            if(leftFromRight[right]==0 || dfs(leftFromRight[right])){
                leftFromRight[right] = node;
                leftFromRight[node] = right;
                // cout<<node<<" "<<right<<"\n";
                return true;
            }
        }

        return false;
    }
    

    int solve(){
        int answer=0;
        for(int i=1; i<N*2+1; ++i){
            if(leftFromRight[i]!=0)continue;
            
            visited = vector<bool>(N*2 + 1, false);
            
            dfs(i);
        }

        for(int i=1; i<N*2+1; ++i){
            if(leftFromRight[i]!=0)++answer;
        }

        return 2*N - answer/2;
    }
};

int main(){
    int T, N, W;
    cin>>T;

    vector<vector<int>> pentagon;

    vector<Solver> solvers;

    for(int i=0; i<T; ++i){
        cin>>N>>W;

        pentagon = vector<vector<int>>(2, vector<int>(N, 0));
        for(int j=0; j<2; ++j){
            for(int k=0; k<N; ++k){
                cin>>pentagon[j][k];
            }
        }
        Solver tmp(pentagon, W, N);
        solvers.push_back(std::move(tmp));
    }

    for(auto s : solvers){
        auto K = s.solve();
        cout<<K<<"\n";
    }
}