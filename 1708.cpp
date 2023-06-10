#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


vector<pair<long long, long long>> coordinates;

vector<pair<long long, long long>> convex_hul;

float gradient(pair<long long, long long> left, pair<long long, long long> right){
    if(right.first-left.first==0)return right.second>left.second?__FLT_MAX__:-__FLT_MAX__;
    return (float)(right.second-left.second)/(float)(right.first-left.first);
}

long long dist(pair<long long, long long> left, pair<long long, long long> right){
    return (left.first-right.first)*(left.first-right.first)+(left.second-right.second)*(left.second-right.second);
}

long long ccw(pair<long long, long long> left, pair<long long, long long> right){
    return left.second*right.first - left.first*right.second;
}

void get_sorted(){

    sort(coordinates.begin(), coordinates.end());
    auto first = *coordinates.begin();

    sort(coordinates.begin()+1, coordinates.end(), [&](pair<long long, long long> a, pair<long long, long long> b){
        auto g_a = gradient(first, a);
        auto g_b = gradient(first, b);
        if(g_a==g_b)return dist(first, a)<dist(first, b);
        
        return gradient(first, a)<gradient(first, b);
    });


}

void get_convex(){
    convex_hul.push_back(coordinates.at(0));
    convex_hul.push_back(coordinates.at(1));
    auto now = coordinates.begin()+2;

    for(;now!=coordinates.end(); ++now){

        while(convex_hul.size()>=2){

        auto first = *(convex_hul.end()-2);
        auto second = *(convex_hul.end()-1);
        auto third = *now;
        auto prev = pair<long long, long long>{third.first-second.first, third.second-second.second};
        auto next = pair<long long, long long>{second.first-first.first, second.second-first.second};
        
        if(ccw(prev, next)>0)break;
        convex_hul.pop_back();
        
    }

    convex_hul.push_back(*now);}
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long N;
    cin>>N;
    for(long long i=0; i<N; ++i){
        coordinates.push_back({0, 0});
        cin>>coordinates.back().first>>coordinates.back().second;
    }

    get_sorted();
    // cout<<"\n";
    // for(auto p : coordinates){
    //     cout<<p.first<<" "<<p.second<<"\n";
    // }

    get_convex();
    // cout<<"\n";
    // for(auto p : convex_hul){
    //     cout<<p.first<<" "<<p.second<<"\n";
    // }

    cout<<convex_hul.size();
}