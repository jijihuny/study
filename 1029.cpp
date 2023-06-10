#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

vector<vector<int>> edges = vector<vector<int>>(15, vector<int>(15, 0));

int visited;

string arr[15];

int MAX_SIZE;

int N = 0;

void dfs(int node, int cost, int iter) {
    
    N = iter > N ? iter : N;

    

    for(int next=1; next<MAX_SIZE; ++next) {

        if(N==MAX_SIZE) {
            cout<<N;
            exit(0);
        }

        if(visited & (1 << next))
            continue;
        //pass if visited node.

        if(edges[node][next]<cost)
            continue;
        //pass if cost is lower than now.
        
        visited |= (1 << next);

        dfs(next, edges[node][next], iter+1);

        visited &= ~(1 << next);      
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    

    cin>>MAX_SIZE;

    

    for(int i=0; i<MAX_SIZE; ++i) {
        cin >> arr[i];
    }

    for(int i=0; i<MAX_SIZE; ++i) {
        for(int j=0; j<MAX_SIZE; ++j) {
            edges[i][j] = arr[i][j] - '0';
        }
    }


    visited = 1;

    dfs(0, 0, 1);

    cout<<N<<"\n";
}