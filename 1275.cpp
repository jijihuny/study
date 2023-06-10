#include <iostream>
using namespace std;

long long arr[100000];

long long seg_tree[400001]={};



void init(long long start, long long end, long long idx){
    if(start==end){
        seg_tree[idx]=arr[start];
        return;
    }

    long long mid = (start + end) / 2;

    init(start, mid, idx*2);
    init(mid+1, end, idx*2+1);

    seg_tree[idx]=seg_tree[idx*2]+seg_tree[idx*2+1];
}

long long find_sum(long long start, long long end, long long query_start, long long query_end, long long node){
    if(query_end<start || query_start > end)return 0;
    if(query_start<=start && end<=query_end)return seg_tree[node];

    long long mid = (start+end)/2;

    return find_sum(start, mid, query_start, query_end, node*2) +
            find_sum(mid+1, end, query_start, query_end, node*2+1);
}

void update_tree(long long start, long long end, long long node, long long idx, long long new_val){
    long long diff = new_val - arr[idx];
    if(idx<start || idx > end)return;
    seg_tree[node] += diff;
    if(start==end)return;
    
    long long mid = (start+end)/2;

    update_tree(start, mid, node*2, idx, new_val);
    update_tree(mid+1, end, node*2+1, idx, new_val);
}


int main(){
    int N, Q;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>Q;

    for(int i=0; i<N; i++)cin>>arr[i];

    init(0, N-1, 1);

    long long query[Q][4];

    for(int i=0; i<Q; i++){
        for(int j=0; j<4; j++){
            cin>>query[i][j];
        }
    }    

    for(int i=0; i<Q; i++){
        int b = max(query[i][0], query[i][1]);
        int s = min(query[i][0], query[i][1]);
        cout<<find_sum(0, N-1, s-1, b-1, 1)<<"\n";
        
        update_tree(0, N-1, 1, query[i][2]-1, query[i][3]);
        arr[query[i][2]-1]=query[i][3];
        
    }
}