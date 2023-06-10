#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;


const int MAX = 200000;

void upheap(int id, int* heap){
    while(id>1){
        if(heap[id / 2]<=heap[id])break;
        std::swap(heap[id], heap[id/2]);
        id /= 2;
    }
}

void insert_heap(int value, int* heap, int n){
    heap[n] = value;
    upheap(n, heap);
}

int visited[MAX]={};
vector<int> sequence;

bool dfs(int N, int k, int p, int* heap, int n){
    int temp[N];
    copy(heap, heap+N, temp);
    
    if(sequence.size()==N){
        if(heap[p]==k)return true;
        else return false;
    }
    for(int i=0; i<N; ++i){
        if(visited[i])continue;

        visited[i]=1;

        sequence.push_back(i);

        insert_heap(i, temp, n+1);

        if(dfs(N, k, p, temp, n+1)){
            return true;
        }

        visited[i]=0;
        sequence.pop_back();
    }

    return false;
}

