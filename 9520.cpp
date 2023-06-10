#include <iostream>
#include <algorithm>

using namespace std;

// DP solution \
S[i][j] : array that stores the minimum TSP cost \
i-th and j-th areas. \
A[i][j] : array that stores the cost between i-th, j-th areas.\
For every cities, S[i][j] = S[i][j-1] + A[j-1][j] if i!=j-1\
                    else min(for(k=0~j-2) S[j-1][k]+A[k][j])\
The fianl answer for N inputs is min(for(k=0~N-1) S[k][N])\
Thus the time complexity is O(N^2).


int S[1500][1500]={};
int A[1500][1500]={};

int main(){
    
    cin.tie(NULL)->sync_with_stdio(false);


    int N;


    cin>>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)cin>>A[i][j];
    }


    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(i-1!=j)S[i][j]=S[i-1][j] + A[i-1][i];
            else {
                if(i==1){S[i][j]=A[i][j];continue;}
                auto k =min_element(S[i-1], S[i-1]+i-1, [&](
                    const int &a, const int &b
                ){
                    return a + A[i][&a-S[i-1]] < b + A[i][&b-S[i-1]];
                });

                S[i][j] = *k + A[i][k-S[i-1]];
            }
        }
    }


    cout<<*min_element(S[N-1], S[N-1]+N-1);
}