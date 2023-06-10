#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> s;
int l[9];
int e[9]={};
void dfs(int n, int N, int M){
    if(s.size()==M){
        for(auto i : s)cout<<l[i]<<" ";

        cout<<"\n";
        return;
    }
    int temp=0;
    for(int i=n; i<=N; i++){
        if(temp==l[i])continue;
        
        // if(e[i]==1)continue;
        temp=l[i];
        s.push_back(i);
        // e[i]=1;
        dfs(i, N, M);
        
        s.pop_back();
        // e[i]=0;
        
    }
}

int main(){
    int N, M;

    cin>>N>>M;

    for(int i=1; i<N+1; i++){
        cin>>l[i];
    }

    sort(l+1, l+1+N);
    
    dfs(1, N, M);
}