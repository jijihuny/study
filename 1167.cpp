#include <iostream>

#include <vector>

using namespace std;

typedef long long ll;
vector<pair<ll, ll>> vertex[100001];

bool visited[100001];



pair<ll, ll> dfs(ll node){
    ll there=0;
    ll cost=0;
    pair<ll, ll> answer={node, 0};
    for(auto edge : vertex[node]){
        there = edge.first;
        cost = edge.second;

        if(visited[there])continue;

        visited[there]=1;
        auto temp = dfs(there);

        if(temp.second+cost>answer.second){
            answer = {temp.first, temp.second+cost};
        }
        visited[there]=0;
    }

    return answer;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    int V;
    cin>>V;


    int node, there, cost;
    for(int i=0; i<V; i++){
        cin>>node;

        while(1){
            cin>>there;
            if(there==-1)break;
            cin>>cost;

            vertex[node].push_back({there, cost});
        }
    }

    visited[1]=1;
    auto t = dfs(1);
    visited[1]=0;
    visited[t.first]=1;
    auto k = dfs(t.first);
    visited[k.first]=0;

    cout<<k.second;
}