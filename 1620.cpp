#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main(){

    int N, M;
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin>>N>>M;

    string A[N+1];
    unordered_map <string, int> B;
    
    for(int i=1; i<N+1; i++){
        cin>>A[i];
        B.insert({A[i], i});
    }

    string temp;
    string buf[M];
    for(int i=0; i<M; i++){
        cin>>temp;

        if(temp[0]<='9' && temp[0]>='0')
            {
                int digits = stoi(temp);
                buf[i] = A[digits];
            }
        else
            {
                buf[i]=to_string(B[temp]);
            }
    }

    for(int i=0; i<M; i++){
        cout<<buf[i]<<"\n";
    }
}