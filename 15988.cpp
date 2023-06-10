#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



typedef long long money;

vector<pair<money, money>> log_list;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    
    cin>>N;
    
    log_list = vector<pair<money, money>>(2*N, {0LL, 0LL});

    for(int i=1; i<=N; ++i){
        cin>>log_list[i].first>>log_list[i].second;
    }

    vector<money> dec;
    
    money minimum_divisor=0;

    
    for(int i=1; i<=N; ++i){
        if(log_list[i].first<0&&(log_list[i].first+log_list[i-1].second<0)){
            if(minimum_divisor<log_list[i].second)minimum_divisor=log_list[i].second;

            dec.push_back(log_list[i].second-log_list[i].first-log_list[i-1].second);
        }
        else{
            if(log_list[i].first+log_list[i-1].second!=log_list[i].second){
                cout<<-1;
                return 0;
            }
        }
    }
    if(dec.size()==0) {cout<<1;return 0;}
    while(dec.size()!=1){
        auto first = dec.back(); dec.pop_back();
        auto second = dec.back(); dec.pop_back();

        auto common_divisor = __gcd(first, second);

        dec.push_back(common_divisor);
        if(common_divisor<=minimum_divisor){
            dec.push_back(-1LL);
            break;}
    }

    cout<<dec.back();
}