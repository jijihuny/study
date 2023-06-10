#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> k;

string pattern, text;

void preprocessing() {

    int matched = 0;

    k = vector<int>(pattern.size(), 0);

    for(int j=1; j<pattern.size(); ++j) {
        if(pattern[matched]==pattern[j]) {
            k[j] = ++matched;
        }
        else {
            if(pattern[j] == pattern[k[matched-1]]) {
                k[j] = matched = k[matched-1] + 1;
            }
            else{
                k[j] = matched = 0;
            }
        }
    }
}

int N=0;

vector<int> loc;

void kmp() {

    int matched = 0;

    for(int i=0; i<text.size(); ++i) {
        if(matched==pattern.size()) {
            ++N;

            matched = k[matched-1];

            

            loc.push_back(i - pattern.size() + 1);
        }

        if(pattern[matched]==text[i]){
            ++matched;
        }
        else {
            if(matched==0)
                continue;

            matched = k[matched-1];
            --i;
        }
    }
}


int main() {

    text = string();
    // cin.ignore();
    getline(cin, text, '\n');

    cin>>pattern;

    preprocessing();

    kmp();

    cout<<N<<'\n';

    for(auto e : loc) {
        cout<<e<<" ";
    }
}