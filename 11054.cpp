#include <iostream>
#include <algorithm>



using namespace std;


short int LIS(short int* A, short int n, short int max = INT16_MAX){

    if(n==0) return 0;
    
    short int R[n];
    short int max_len=0;
    for(int i=0;i<n;i++){
        R[i]=INT16_MAX;
    }
    for(int i=0; i<n; i++){
        if(A[i]>=max)continue;

        if(A[i]>R[max_len]){
            R[++max_len]=A[i];
        }
        else{
            auto idx = lower_bound(R, R+max_len, A[i]);
            if(A[i]<*idx)
                *idx = A[i];
        }
    }
    return max_len+1;    
}

short int LDS(short int* A, short int n, short int max=INT16_MAX){
    short int R[n]={};
    reverse_copy(A, A+n, R);

    return LIS(R, n, max);
}

short int LBS(short int* A, short int n){
    
    short int* max_val[n]={};
    short int num_max = 1;
    max_val[0] = max_element(A, A+n);


    short int length = 0;
    short int temp = 0;
    for(int i=0;i<n;i++){
        if(i!=1){
            for(int j=0; j<i;j++){
                *max_val[j]=0;
            }
        }

        max_val[i] = max_element(A, A+n);
        
        if(i!=1){
            for(int j=0; j<i;j++){
                *max_val[j]=INT16_MAX;
            }
            if(length>=2*(*max_val[i])-1)break;
        }
        temp = 0;
        short int inc = max_val[i] - A;
        short int dec = n - inc;
        
        short int temp1 = LIS(A, inc, *max_val[i]);
        short int temp2 = LDS(A+inc, dec, *max_val[i]+1);
        temp = temp1 + temp2;
        if(length<temp)length=temp;
    }

    return length;
}    
    



int main(){
    short int n;
    
    cin>>n;

    short int A[n];

    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout<<LBS(A, n);
}