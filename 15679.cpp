#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> s;
int e[9]={};
void dfs(int N, int M){
    if(s.size()==M){
        for(auto i : s)cout<<i<<" ";

        cout<<"\n";
        return;
    }

    for(int i=1; i<=N; i++){
        if(e[i]==1)continue;
        s.push_back(i);
        e[i]=1;
        dfs(N, M);
        s.pop_back();
        e[i]=0;

    }
}

int main(){
    int N, M;

    cin>>N>>M;
    
    dfs(N, M);
}