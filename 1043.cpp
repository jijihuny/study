#include <iostream>
#include <vector>



using namespace std;


vector<vector<int>> edges(51, vector<int>());
vector<vector<int>> party(51, vector<int>());
vector<bool> visited(51, 0);

vector<int> right_to_left_node(51, 0);
vector<bool> known(51, 0);


void dfs(int people){
    // visited[left] = 1;

    // for(auto &right : edges[left]){
    //     if(visited[right_to_left_node[right]])continue;

    //     if(!right_to_left_node[right] || dfs(right_to_left_node[right])){
    //         right_to_left_node[right] = left;

    //         return true;
    //     }
    // }

    // return false;
    visited[people] = true;
    known[people] = true;

    for(auto &each_party : edges[people]){
        for(auto &partner : party[each_party]){
            if(visited[partner])continue;
            dfs(partner);
        }
    }
}



auto getInput(){
    int N, M, T;

    cin>>N>>M>>T;


    int temp;
    for(int i=0; i<T; ++i){
        cin>>temp;

        known[temp] = 1;
    }

    
    int people;
    for(int i=1; i<=M; ++i){
        cin>>people;


        party[i].assign(people, 0);
        for(int j=0; j<people; ++j){
            cin>>party[i][j];
        }

        for(int j=0; j<people; ++j){
            edges[party[i][j]].push_back(i);
        }
    }

    return pair<int, int>{N, M};
}

void solve(){
    auto p = getInput();
    int N = p.first, M = p.second;
    int answer=0;
    for(int i=1; i<=N; ++i){
        if(known[i]){
            dfs(i);
        }
    }

    for(int i=1; i<=M; ++i){
        if(!known[party[i][0]])answer++;
    }

    cout<<answer;
}


int main(){
    cin.tie(NULL)->sync_with_stdio(false);


    solve();
}