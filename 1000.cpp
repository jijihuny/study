#include <iostream>
#include <numeric>

using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i, j;
    for(;;){
        cin>>i>>j;
        if(i==0 && j==0) return 0;

        if(j%i==0)cout<<"factor"<<endl;
        else if(i%j==0) cout<<"multiple"<<endl;
        else cout<<"neither"<<endl;
    }
}