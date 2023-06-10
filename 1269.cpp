#include <iostream>
#include <algorithm>

using namespace std;

bool cnt(const int &a){
    return *(&a-1)!=a && a!=*(&a+1);
}

int main(){
    int N, M;

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    cin>>N>>M;
    int A[N+M];
    for(int i=0; i<N+M; i++){
        cin>>A[i];
    }

    sort(A, A+N+M);

    cout<<count_if(A, A+N+M, cnt);
}