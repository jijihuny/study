#include <iostream>

#include <vector>

#define MAX_SIZE 1000000

using namespace std;


int N=MAX_SIZE;

int K=10000;
int M=10000;

vector<long long> arr(N+1, 0);
vector<long long> tree(4*N, 0);

long long init(int start, int end, int idx){
    if(start==end){
        tree[idx]=arr[start];
        return tree[idx];
    }

    int mid = (start + end) / 2;

    tree[idx] = init(start, mid, idx*2) + init(mid+1, end, idx*2+1);
    return tree[idx];
}


long long interval_sum(int start, int end, int idx, int left, int right){
    if(left>end || right<start)return 0;

    if(left<=start && right >= end)return tree[idx];

    int mid = (start + end)/2;

    return interval_sum(start, mid, idx*2, left, right) + interval_sum(mid+1, end, idx*2+1, left, right);
}

void update(int start, int end, int idx, int what, long long value){
    if(what<start | what>end)return;

    tree[idx] += value;
    if(start==end)return;
    int mid = (start+end)/2;
    update(start, mid, idx*2, what, value);
    update(mid+1, end, idx*2+1, what, value);
}

vector<vector<long long>> query;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>N>>M>>K;

    for(int i=0; i<N; i++){
        cin>>arr[i+1];
    }
    long long temp1, temp2, temp3;
    for(int i=0; i<M+K; i++){
        cin>>temp1>>temp2>>temp3;

        query.push_back({temp1, temp2, temp3});
    }

    init(1, N, 1);

    for(auto i : query){
        if(i.at(0)==1){
            long long dx = i.at(2)-arr[i.at(1)];
            arr[i.at(1)]=i.at(2);

            update(1, N, 1, i.at(1), dx);
        }
        else if(i.at(0)==2){
            cout<<interval_sum(1, N, 1, i.at(1), i.at(2))<<"\n";
        }
    }
}