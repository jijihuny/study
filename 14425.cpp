#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

bool cmp(const string& a,const string& b){
    int i=0;
    while(i<=a.length() && i<=b.length()){
        if(a[i]==b[i]){
            i++;
            continue;
        }
        else return a[i]<b[i];
    }
    return a.length() < b.length();
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin>>N>>M;

    
    vector<string> A(N);
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    

    
    sort(A.begin(), A.end(), cmp);


    string temp_key[M];
    
    int count=0;

    for(int i=0; i<M; i++){
        cin>>temp_key[i];
        
    }
    
    for(int i=0; i<M;i++){
        auto temp = lower_bound(A.begin(), A.end(), temp_key[i], cmp);
        
        
        if (*temp == temp_key[i])count++;
    }

    cout<<count;
}