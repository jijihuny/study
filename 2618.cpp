#include <iostream>
#include <vector>

using namespace std;



vector<pair<int, int>> dp;

int size_max;

vector<pair<int, int>> events;

void getInput(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, W;

    cin>>N>>W;
    
    size_max = W-1;

    dp.assign(W+1, {0, 0});

    events.assign(W+1, {0, 0});

    for(int i = 1; i<=W; ++i){
        cin>>events[i].first>>events[i].second;
    }
}

void solve(){
    getInput();

    for(int i=1; i<=W; ++i){
        pair<int, int> temp;

        
    }
}