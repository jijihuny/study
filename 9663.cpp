#include <iostream>
#include <stdlib.h>

using namespace std;

int cases=0;






void dfs(short int n, short int* col={}, short int t=0){
    short int flag=1;
    
    if(t==n){
        cases++;
        return;
    }
    if(t==0)col = new short int[n]{};


    for(short int i=0; i<n; i++){
        
        flag=1;

        for(short int j=0; j<t; j++){
            if(i == col[j] || (t-j)==abs(col[j]-i)){
                flag=0;
                break;
            }
        }

        if(flag==1){
            col[t]=i;
            dfs(n, col, t+1);
        }
    }

    if(t==0)delete[] col;
}

int main(){
    short int n;
    cin>>n;

    dfs(n);

    printf("%d", cases);

    return 0;
}