#include <iostream>
#include <queue>
#include <set>

using namespace std;

queue<set<int>> q;

vector<int> vertex[100001];

vector<int> sequence;

bool visited[100001]={};

bool bfs(vector<int>::iterator first, vector<int>::iterator end){
    if(first==end)return true;
    if(q.empty())return false;
    
    auto elem = first;
    while(!q.empty()){
        auto s = q.front();
        while(!s.empty()&&elem!=end){
            if(*s.lower_bound(*elem)==*elem)s.erase(*elem);
            else return false;
            elem++;
        }
        q.pop();
    }

    for(auto i=first; i!=elem; i++){
        visited[*i]=1;
        set<int> temp;
        for(auto j : vertex[*i]){
            if(!visited[j])temp.insert(j);
        }
        q.push(temp);
    }

    return bfs(elem, end);
}


int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int N;
    cin>>N;
    int temp1, temp2;
    for(int i=0; i<N-1; i++){
        cin>>temp1>>temp2;

        vertex[temp1].push_back(temp2);
        vertex[temp2].push_back(temp1);
    }

    q.push({1});
    
    for(int i=0; i<N; i++){
        cin>>temp1;
        sequence.push_back(temp1);
    }

    cout<<bfs(sequence.begin(), sequence.end());
}