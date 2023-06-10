#include <iostream>
#include <algorithm>
using namespace std;

int *files;

int merged_size[500][500]={};
int total_cost[500][500]={};

void fill_mc(int N){
    for(int i=0; i<N; i++){
        for(int j=i; j>=0; j--){
            if(i==j){
                merged_size[i][j]=files[i];
                total_cost[i][j]=0;
            }
            else{
                merged_size[i][j]=merged_size[j][j]+merged_size[i][j+1];
                total_cost[i][j]=INT32_MAX;
                for(int k=j; k<i; k++){
                    int temp_cost = total_cost[k][j]+total_cost[i][k+1];

                    total_cost[i][j] = temp_cost+merged_size[i][j]<total_cost[i][j]?temp_cost+merged_size[i][j]:total_cost[i][j];
                }
            }
        }

    }
}



int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int T;
    cin>>T;

    int K[T];

    int f[T][500];
    for(int i=0; i<T; i++){
        cin>>K[i];
        for(int j=0; j<K[i]; j++){
            cin>>f[i][j];
        }
    }

    for(int i=0; i<T; i++){
        files=f[i];
        fill_mc(K[i]);
        cout<<total_cost[K[i]-1][0]<<"\n";
    }
}