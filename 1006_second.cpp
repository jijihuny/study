#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int Enemy[30][2][10000]={};
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
                    mcount += (j-t+1)/2;//(j-t==1?2:j-t)/2;
                    j++;
                }

                // cout<<"mcount for "<<i<<","<<j<<"is"<<mcount<<"\n";
            }

            if(zero_point_flag[i]){
                auto first = upper_bound(arr[i], arr[i]+N, arr[i][0]);
                auto last = lower_bound(arr[i], arr[i]+N, arr[i][N-1]);
                // cout<<*first<<" "<<*last<<"\n";
                // cout<<first-arr[i]<<" "<<arr[i]+N-last<<'\n';
                if((first-arr[i])%2==1 && (arr[i]+N-last)%2==1)mcount++;
                // cout<<"incremented"<<first-arr[i]<<" "<<<<'\n';
            }

        }
        // cout<<"for case"<<l<<"\n";
        // for(int i=0; i<2; i++){
        //     for(int j=0; j<N; j++)cout<<arr[i][j]<<" ";
        //     cout<<"\n";
        // }

        //second loop. calculate vertical informaion.
        for(int j=0; j<N; j++){
            if(E[0][j]+E[1][j]<=W)vertical.push_back(j);
        }

        // cout<<"js"<<"\n";
        // for(auto k:vertical)cout<<k<<" ";

        //third loop. calculate whether the vertical lines are valid or not.
        for(auto j =vertical.begin(); j!=vertical.end();){
            
            auto u0 = upper_bound(arr[0], arr[0]+N, (zero_point_flag[0]&&arr[0][*j]==arr[0][N-1]?arr[0][0]:arr[0][*j]));
            auto l0 = lower_bound(arr[0], arr[0]+N, (zero_point_flag[0]&&arr[0][*j]==arr[0][0]?arr[0][N-1]:arr[0][*j]));
            auto u1 = upper_bound(arr[1], arr[1]+N, (zero_point_flag[1]&&arr[1][*j]==arr[1][N-1]?arr[1][0]:arr[1][*j]));
            auto l1 = lower_bound(arr[1], arr[1]+N, (zero_point_flag[1]&&arr[1][*j]==arr[1][0]?arr[1][N-1]:arr[1][*j]));
            //  cout<<*j<<" in test"<<l<<'\n';

            // cout<<"for "<<*j<<" u0, l0, u1, l1 is"<<*u0<<" "<<*l0<<" "<<*u1<<" "<<*l1<<'\n';
            // cout<<"((u0-l0+N)%N)%2==1 : "<<(((u0-l0+N)%(N+1))%2==1)<<" ((*j-*l0+N)%N)%2==0 : "<<(((*j-*l0+N)%N)%2==0)<<" ((u1-l1+N)%N)%2==1 :"<<(((u1-l1+N)%(N+1))%2==1)<<" ((*j-*l1+N)%N)%2==0 : "<<(((*j-*l1+N)%N)%2==1)<<"\n";
            if(((u0+N-l0)%N)%2==1 && (((*j+N)-*l0)%N)%2==0 &&
                ((u1+N-l1)%N)%2==1 && (((*j+N)-*l1)%N)%2==0){
                    mcount++;
                    j++;
                    while((arr[0]+*j<u0 || arr[1]+*j<u1)&&j!=vertical.end()){j++;}
                }
            else j++;
            

            
        }

        cout<<2*N-mcount<<'\n';
        vertical.clear();
    }
}