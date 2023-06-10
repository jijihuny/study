#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Enemy[3][2][10000]={};
int arr[2][10000]={};
vector<int> vertical;

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int T;

    cin>>T;

    int n[T], w[T];

    for(int i=0; i<T; i++){
        cin>>n[i]>>w[i];

        for(int j=0; j<2; j++){
            for(int k=0; k<n[i]; k++){
                cin>>Enemy[i][j][k];
            }
        }
    }




    for(int l=0; l<T; l++){
        int N=n[l], W=w[l];
        auto E = Enemy[l];
        bool zero_point_flag[2] = {(E[0][0]+E[0][N-1]<=W), (E[1][0]+E[1][N-1]<=W)};
        int mcount=0;

        //first loop. storing arr. calculate horizental informaion.
        for(int i=0; i<2; i++){
            
            for(int j=0; j<N;){
                if(E[i][j]+E[i][j+1]>W){
                    arr[i][j]=j;
                    j++;
                }
                else{
                    
                    int t=j;
                    arr[i][j]=t;
                    while(E[i][j]+E[i][j+1]<=W && j<N-1)arr[i][++j] = t;
                    j++;
                    mcount += (j-t==1?2:j-t)/2;
                }
            }

        if(zero_point_flag[i]){
            auto first = upper
            
        }

        }

        for(int i=0; i<2; i++){
            for(int j=0; j<N; j++)cout<<arr[i][j]<<" ";
            cout<<"\n";
        }

        //second loop. calculate vertical informaion.
        for(int j=0; j<N; j++){
            if(E[0][j]+E[1][j]<=W)vertical.push_back(j);
        }

        //third loop. calculate whether the vertical lines are valid or not.
        for(auto j =vertical.begin(); j!=vertical.end();){
            
            auto u0 = upper_bound(arr[0], arr[0]+N, arr[0][*j]);
            auto l0 = lower_bound(arr[0], arr[0]+*j+1, arr[0][*j]);
            auto u1 = upper_bound(arr[1], arr[1]+N, arr[1][*j]);
            auto l1 = lower_bound(arr[1], arr[1]+*j+1, arr[1][*j]);
            cout<<*j<<" ";
            // bool flag[2]={};
            
            // if((u0-l0)==1 || ((u0-l0)%2==0 && (*j-*l0)%2==0))flag[0]=1;
            // if((u1-l1)==1 || ((u1-l1)%2==0 && (*j-*l1)%2==0))flag[1]=1;

            // //to check zero.
            

            // if(flag[0]&&flag[1])mcount++;
            while(arr[0][*j]==*l0 || arr[1][*j]==*l1)j++;
        }

        cout<<mcount<<'\n';
        vertical.clear();
    }
}