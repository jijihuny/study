#include <iostream>
#include <algorithm>

using namespace std;


int sums[100001]={};
void sum(int* A, int n, int* R){
    R[0]=0;
    for(int i=1; i<n+1; i++){
        R[i] = R[i-1] + A[i-1];
    }
}

int sum_of_interval(int* R, int i, int j){
    int sum=0;
    sum = R[j] - R[i-1];
    return sum;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin>>N>>M;

    int A[N];

    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    sum(A, N, sums);


    int B[M][2];
    for(int i=0;i<M;i++){
        cin>>B[i][0]>>B[i][1];
    }

    for(int i=0;i<M;i++){
        cout<<sum_of_interval(sums, B[i][0], B[i][1])<<"\n";
    }
}