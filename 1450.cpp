#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define i_th(i) (1 << i)

using namespace std;

long long fac[30]={1, 1};

long long factorial(int x){
    if(fac[x]==0) fac[x]=x * factorial(x-1);

    return fac[x];
}


int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, C;

    cin>>N>>C;

    int A[N]={};

    for(int i=0; i<N; i++)cin>>A[i];

    sort(A, A+N);
    int* A_end;
    if(A[N]>C)A_end=upper_bound(A, A+N, C);
    else A_end = A+N;

    N = A_end - A;//resize


    int M1 = N%2==0 ? N/2 : N/2 +1, M2 = N/2;
    
    int first_half[(int)exp2(M1)], second_half[(int)exp2(M2)];


    vector<bool> v1(M1, false);
    int count=0;

    auto f1 = [&](int &a){
        if(!next_permutation(v1.begin(), v1.end())){
            count++;
            v1.assign(count, true);
        }
        for(int i=0; i<M1; i++){
            if(v1.at(i))a+=A[i];
        }       
    };
    for_each(first_half, first_half+M1, f1);

    vector<bool> v2(M2, false);
    count=0;
    auto f2 = [&](int &a){
        if(!next_permutation(v2.begin(), v2.end())){
            count++;
            v2.assign(count, true);
        }
        for(int i=0; i<M2; i++){
            if(v2.at(i))a+=A[M1+i];
        }
    };

    for_each(second_half, second_half+M2, f2);
    sort(first_half, first_half+M1);
    sort(second_half, second_half+M2);
    for(auto i=first_half, j=second_half+M2; i!=first_half+M1; i++){
        
    }
}
