#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;


unordered_map<string, int> id;

int N;

int friendship[200001]={};
int members[200001]={};

int find_friend(int id){
    if(friendship[id]==id)return id;

    return friendship[id]=find_friend(friendship[id]);
}

// bool isUnion(int id_me, int id_you){
//     int me = find_friend(id_me);
//     int you = find_friend(id_you);

//     if(me==you)return true;
//     else return false;
// }

void merge(int id_me, int id_you){
    int me = find_friend(id_me);
    int you = find_friend(id_you);

    if(me==you)return;
    members[me] += members[you];
    friendship[you]=me;
}

vector<int> answer;

void get_input(){
    
    cin>>N;
    

    id.clear();
    id.reserve(N+1);
    iota(friendship, friendship+2*N+1, 0);
    fill_n(members, 2*N+1, 1);

    string me, you;
    int id_number=0;

    for(int i=0; i<N; i++){
        cin>>me>>you;
        for(auto user : {me, you}){
            if(id.find(user)==id.end()){
                id.insert({user, id_number++});
            }
        }
        
        merge(id.at(me), id.at(you));
        answer.push_back(members[friendship[id.at(me)]]);
    }

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=0;
    cin>>T;

    for(int i=0; i<T; i++){
        
        get_input();
    }

    for(auto p : answer)cout<<p<<"\n";
}
