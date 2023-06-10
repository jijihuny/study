#include <iostream>

#include <algorithm>
#include <queue>
#include <map>

using namespace std;



int find(int x, int parent[]){
    if(parent[x] != x) parent[x] = find(parent[x], parent);

    return parent[x];
}

void union_(int x, int y, int parent[]){

    if(x < y)
        parent[x] = y;
    else if(x > y)
        parent[y] = x;
}



int abmin(const vector<int> a, const vector<int> b){
    return min({abs(a[3]-b[3]), abs(a[1]-b[1]), abs(a[2]-b[2])});
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;

    vector<vector<int>> A(N, vector<int>(4));
    int parent[N];
    for(int i=0; i<N; i++)
        {   A[i][0] = i;
            cin>> A[i][1] >> A[i][2] >> A[i][3];}



    auto compare = [](const vector<int> &a, const vector<int> &b){ return a.at(2)>b.at(2); };
    priority_queue<vector<int>, deque<vector<int>>, decltype(compare)> q(compare);
    

    for_each(parent, parent+N, [&](int &a){ a = &a - parent;});
    int max =0;
    int cnt=0;
    
    auto x_cmp = [](const vector<int> a, const vector<int> b){return a[1]<b[1];};
    stable_sort(A.begin(), A.end(), x_cmp);
    for(int i=0; i<N-1; i++){
        q.push({A[i][0], A[i+1][0], abmin(A[i], A[i+1])});
    }
    
    stable_sort(A.begin(), A.end(), [](const vector<int> a, const vector<int> b){return a[2]<b[2];});
    for(int i=0; i<N-1; i++){
        q.push({A[i][0], A[i+1][0], abmin(A[i], A[i+1])});
    }
    
    stable_sort(A.begin(), A.end(), [](const vector<int> a, const vector<int> b){return a[3]<b[3];});
    for(int i=0; i<N-1; i++){
        q.push({A[i][0], A[i+1][0], abmin(A[i], A[i+1])});
    }
    
    int count = 0;
    size_t res = 0;
    for(;count<N-1;){
        auto temp = q.top();
        auto root_x = find(temp.at(0), parent), root_y=find(temp.at(1), parent);
        if(root_x != root_y){
            count++;
            union_(root_x, root_y, parent);
            res+=temp.at(2);
        }
        q.pop();
    }

    cout<<res;
}