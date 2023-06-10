#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> s;
int e[9]={};
void dfs(int n, int N, int M){
    if(s.size()==M){
        for(auto i : s)cout<<i<<" ";

        cout<<"\n";
        return;
    }

    for(int i=1; i<=N; i++){
        
        s.push_back(i);
        
        dfs(i, N, M);
        s.pop_back();

    }
}

int main(){
    int N, M;

    cin>>N>>M;
    
    dfs(1, N, M);
}