#include <iostream>
#include <algorithm>

#include <unordered_map>
#include <vector>
using namespace std;

vector<int> orig;
vector<int> uniq;

unordered_map<int, int> sizeEach;

void makeUniqueArray(){
    for(const auto &each : orig){
        // is it first?
        if(sizeEach.find(each)==sizeEach.end()){
            sizeEach.insert({each, 1});
            uniq.push_back(each);
        }
        else{
            ++sizeEach[each];
        }
    }
}

void makeOrigArray(){
    vector<int> tmp;
    for(const auto &each : uniq){
        for(int r=0; r<sizeEach[each]; ++r){
            tmp.push_back(each);
        }
    }

    orig = std::move(tmp);
}

void getInput(){
    int N;
    cin>>N;
    orig = vector<int>(N, 0);
    for(auto &each : orig){
        cin>>each;
    }
}

void dfs(vector<int> &dst){
    static vector<bool> visited(orig.size(), false);
    if(dst.size()==orig.size())return;


    if(dst.empty()){dst.push_back(orig.front());
    visited[0]=true;}
    int idx = 0;
    for(auto &each : orig){
        if(visited[idx++])continue;
        

        if(dst.back()+1==each){
            continue;
        }
        visited[idx-1] = true;
        dst.push_back(each);

        dfs(dst);

        return;
    }
    auto dst_end = dst.back();
    

    int i=0;
    while(dst.back()==dst_end){dst.pop_back();++i;}
    while(!(visited.back())){
        dst.push_back(orig.back());
        visited.pop_back();
    }
    while(i--){
        dst.push_back(dst_end);
    }
}

void solve(){
    getInput();

    //Make original array that has repeated element into has only ones.
    // makeUniqueArray();

    //Sort Unique array so we could find continuous integers.
    sort(orig.begin(), orig.end());

    // for(auto each : orig){
    //     cout<<each<<" ";
    // }

    vector<int> tmp;
    dfs(tmp);

    orig = std::move(tmp);

    // makeOrigArray();

    for(auto each : orig){
        cout<<each<<" ";
    }
    cout<<"\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}