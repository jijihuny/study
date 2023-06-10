#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using std::vector;
using std::string;
using std::pair;
using std::sort;
using std::cout;
using std::cin;



vector<string> base36;
vector<string> base36ToDec;

string operator+(const string &x, const string &y);

void greedy(int K){

    vector<pair<char, string>> tmp;
    vector<int> visited(36, -1);
    
    for(auto each : base36ToDec){
        vector<bool> s_visited(36, 0);
        for(auto r_it = each.rbegin(); r_it != each.rend(); ++r_it){
            if(*r_it==35)continue;
            
            char val = *r_it;
            if(s_visited[val])continue;
            s_visited[val]=1;
            string dv(each.begin(), r_it.base());

            for(auto &elem : dv){
                if(elem==val)elem=35-val;
                else elem=0;
            }

            if(visited[val]==-1){
                tmp.push_back({val, dv});
                visited[val] = tmp.size()-1;
            }

            else{
                tmp[visited[val]] = {val, tmp[visited[val]].second + dv};
            }
            

        }
    }

    if(tmp.empty())return;
    sort(tmp.begin(), tmp.end(), [](const pair<char, string> &a, const pair<char, string> &b){
        if(a.second.size()!=b.second.size())return a.second.size()<b.second.size();
        return lexicographical_compare(a.second.rbegin(), a.second.rend(), b.second.rbegin(), b.second.rend());
        // return a.first.front() < b.first.front();
    });


    for(int i=0; i<K && !tmp.empty(); ++i){
        auto selected = tmp.back().first;
        tmp.pop_back();
        for(auto &each : base36ToDec){
            for(auto &elem : each){
                if(elem==selected){
                    elem = 35;
                }
            }
        }
    }
    // greedy(iter+1, K);
}

string operator+(const string &x, const string &y){
    string sum(std::max(x.size(), y.size())+2, 0);
    char c = 0;
    char s = 0;

    if(x.empty() & !y.empty())return y;
    if(!x.empty() & y.empty())return x;


    for(int i = 0; i < sum.size(); ++i){
        s = (i<x.size()?x[i]:0) + (i<y.size()?y[i]:0) + c;

        if(s>35){
            c = s / 36;
            s %= 36;
            
        }
        else c = 0;

        sum[i] = s;
    }

    
    while(sum.empty()?0:sum.back()==0)sum.pop_back();
    if(sum.empty())sum.push_back(0);
    return sum;
}

string toDec(string &a){
    string tmp(a.rbegin(), a.rend());

    for(auto &each : tmp){
        if('0'<=each && each<='9')each-='0';
        else if('A'<=each && each<='Z')each-='A'-10;
    }

    return tmp;
}

string toStr(string &a){
    string tmp(a.rbegin(), a.rend());
    for(auto &each : tmp){
        if(0<=each && each<=9)each+='0';
        else if(10<=each && each<=35)each+='A'-10;
    }

    return tmp;
}


int main(){

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    //input
    cin>>N;

    base36.assign(N, string());

    for(auto &each : base36)cin>>each;

    cin>>K;

    if(N==0){cout<<0;return 0;}
    for(auto &each : base36){
        base36ToDec.push_back(toDec(each));
    }

    //compute K numbers.
    greedy(K);

    

    string sum;

    for(auto &each : base36ToDec){
        sum = sum + each;
    }

    string res = toStr(sum);

    cout<<res;
}