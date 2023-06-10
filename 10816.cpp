#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


unordered_map <int, int> cnt;



int main(){
    int N, M;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;

    int A[N];

    for(int i=0; i<N; i++)cin>>A[i];

    sort(A,A+N);

    cin>>M;

    int B[M];
    
    for(int i=0; i<M; i++){
        cin>>B[i];
    }



    for(int i=0; i<M; i++){
        cout<<upper_bound(A, A+N, B[i])-lower_bound(A, A+N, B[i])<<" ";
    }
}