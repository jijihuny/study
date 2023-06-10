#include <iostream>
#include <list>
#include <vector>
using namespace std;


list<int> multitab;
vector<int> sequence;

bool pluged[100]={};

int answer=INT32_MAX;

int N, K;

void dfs(vector<int>::iterator now=sequence.begin(), int pooled_number=0){
    
    if(now==sequence.end()){
        if(pooled_number<answer)answer=pooled_number;
        return;
    }
    if(pooled_number>=answer)return;

    if(pluged[*now]){
        dfs(now+1, pooled_number);
        return;
    }

    if(multitab.size()<N){
        multitab.push_front(*now);
        pluged[*now]=1;
        dfs(now+1, pooled_number);
        multitab.pop_front();
        pluged[*now]=0;
    }
    else{
        for(auto tabbed = multitab.begin(); tabbed != multitab.end();){
            
            pluged[*tabbed]=0;
            auto temp = *tabbed;
            tabbed = multitab.erase(tabbed);
            pluged[*now]=1;
            multitab.push_front(*now);
            dfs(now+1, pooled_number+1);
            pluged[*now]=0;
            multitab.pop_front();
            multitab.insert(tabbed, temp);
            pluged[temp]=1;

        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>K;

    for(int i=0; i<K; i++){
        sequence.push_back(0);
        cin>>sequence.back();
    }

    dfs();

    cout<<answer;
}