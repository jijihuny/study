// #include <iostream>
// #include <algorithm>
// #include <memory.h>
// #include <math.h>

// using namespace std;

// #define MAX_SIZE (int) 50e4
// #define MOD (int) 1e4
// #define flag (int) 0x7fffffff
// #define offset (int) 10e6


// // int hash_func(int key, int i, int m){
// //     key += offset;
// //     return (key + i * (key % MOD)) % m;
// // }

// // void store_hash(int key, int *A, int m){
// //     int i = 0;
// //     int h = 0;

// //     while(1){
// //         h = hash_func(key, i, m);
// //         if(A[h]==flag){
// //             A[h]=key;
// //             return;
// //         }
// //         i++;
// //     }
// // }

// // bool search_hash(int key, int *A, int m){
// //     int i = 0;
// //     int h = 0;
    
// //     while(1){
// //         h = hash_func(key, i, m);
// //         if(A[h]==key)return 1;
// //         else if(A[h]==flag)return 0;
// //         else i++;
// //     }
// // }

// // int main(){
// //     ios::sync_with_stdio(false);
// //     cin.tie(NULL);
// //     cout.tie(NULL);
    
// //     int N=0, M=0;

// //     cin>>N;

// //     int A[N];

// //     fill(A, A+N, flag);


// //     int temp_key=0;

// //     for(int i=0; i<N; i++){
// //         cin>>temp_key;
// //         store_hash(temp_key, A, N);
// //     }
    
    
// //     cin>>M;
// //     bool Arr[M];
// //     for(int i=0; i<M; i++){
// //         cin>>temp_key;
// //         Arr[i] = search_hash(temp_key, A, N);
// //     }

// //     for(int i=0; i<M; i++){
// //         cout<<Arr[i]<<" ";
// //     }
// // }


// int search_tree(int key, int* A){
//     for(int i=1;;){
//         if(A[i]==flag)return flag;
        
//         if(A[i]==key)return key;
//         else if(A[i]>key)i = 2*i;
//         else if(A[i]<key)i = 2*i+1;
        
//     }
// }

// void store_tree(int key, int* A){
//     for(int i=1;;){
//         if(A[i]==flag){
//             A[i]=key;
//             break;
//         }
        
        
//         else if(A[i]>key)i = 2*i;
//         else if(A[i]<key)i = 2*i+1;       
//     }
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int N, M;


//     cin>>N;

//     int *A = new int[(int)exp2(N)];
        
//     int temp_key;

//     fill(A, A+MAX_SIZE+1, flag);
//     for(int i=0; i<N; i++){
//         cin>>temp_key;
//         store_tree(temp_key, A);
//     }

//     cin>>M;
//     bool res[M];
//     for(int i=0; i<M; i++){
//         cin>>temp_key;
//         if(search_tree(temp_key, A)==temp_key)
//             res[i]=1;
//         else res[i]=0;
//     }
    
//     for(int i=0; i<M; i++){
//         cout<<res[i]<<" ";
//     }

//     delete[] A;
// }

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, M;

    cin>>N;

    int A[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    sort(A, A+N);

    cin>>M;


    int B[M];
    bool R[M];

    for(int i=0;i<M;i++){
        cin>>B[i];
        R[i] = binary_search(A, A+N, B[i]);
    }

    for(int i=0;i<M;i++){
        cout<<R[i]<<" ";
    }
}