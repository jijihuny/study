#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string st;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>st;

    unordered_set <string> A;
    size_t len = st.length();
    for(size_t i=0; i<len; i++){
        for(size_t j=1; j<len-i+1; j++){
            A.insert(st.substr(i, j));
        }
    }

    cout<<A.size();
}