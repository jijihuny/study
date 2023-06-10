#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool prime_numbers[2000]={};

void fill_prime(){
    for(int i=2; i<2000; ++i){
        if(prime_numbers[i]==1)continue;
        for(int j=i*2; j<2000; j+=i)
            prime_numbers[j]=1;
    }
}

vector<int> adj[50];

int visited[50]={};
bool done[50]={};

bool dfs(int here){
    if(done[here])return false;
    done[here]=true;
    for(auto there:adj[here]){
        if(visited[there]==-1 || dfs(visited[there])){
            visited[there]=here;
            return true;
        }
    }

    return false;
}

vector<int> answer;

int numbers[50];

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int N;
    cin>>N;
    fill_prime();
    for(int i=0; i<N; i++){
        cin>>numbers[i];
    }


    vector<int> left;
    vector<int> right;

    for(int i=1; i<N; i++){
        if(numbers[i]%2==numbers[0]%2)right.push_back(numbers[i]);
        else left.push_back(numbers[i]);
    }

    if(left.size()!=right.size()+1){
        cout<<-1;
        return 0;
    }

    for(int i=0; i<left.size(); i++){
        for(int j=0; j<right.size(); j++){
            if(!prime_numbers[left[i]+right[j]])
                adj[i].push_back(j);
        }
    }
    

    for(int i=0; i<left.size(); i++){
        if(!prime_numbers[left[i]+numbers[0]]){
            fill(visited, visited+N, -1);
            
            bool flag=true;
            for(int j=0; j<left.size(); j++){
                if(i==j)continue;
                fill(done, done+N, 0);    
                flag &= dfs(j);
            }
            
            if(flag)answer.push_back(left[i]);
        }
    }

    if(answer.size()==0)cout<<-1;
    else{
        sort(answer.begin(), answer.end());
        for(auto i:answer)cout<<i<<" ";
    }
}