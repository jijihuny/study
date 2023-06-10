#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

bool cmp(const string &a, const string &b){
    return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin>>N>>M;

    vector<string> A; 

    vector<string> B;    
    string temp;
    for(int i=0; i<N+M; i++){
        cin>>temp;
        if(i<N)A.push_back(temp);
        else B.push_back(temp);
    }

    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);
    vector<string> vec(min(N, M));
    
    auto R = set_intersection(A.begin(), A.end(), B.begin(), B.end(), vec.begin(), cmp);
    auto k = R - vec.begin();

    cout<<k<<"\n";
    for(auto i=vec.begin(); i != R; i++)cout<<*i<<'\n';

}