#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>



using namespace std;

long modulo[(int)10e3+1]={};


void mod(int* A, int n, int M){
    modulo[0]=0;
    long sum=0;
    for(int i=1; i<n+1; i++){
        sum = sum + A[i-1];
        int m = sum % M;
        modulo[m]++;
    }
}

long rest(int M){
    long count=0;
    count += modulo[0];
    for(int i=0; i<M; i++){
        count += modulo[i]*(modulo[i]-1)/2;
    }

    return count;
}


int A[(int)10e6]={};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin>>N>>M;

    

    for(int i=0; i<N; i++)cin>>A[i];

    mod(A, N, M);

    cout<<rest(M);

}