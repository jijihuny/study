#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <set>
using namespace std;

stack<char> op;


string postfix;
string midfix;

map<char, int> priorities={{'+', 0}, {'-', 0},
                           {'*', 1}, {'/', 1},
                           {'(', 2}, {')', 2}};

set<char> op_list={'+', '-', '*', '/', '(', ')'};

void getPost(){
    for(auto cur : midfix){
        if('A'<=cur && cur<='Z'){
            postfix.push_back(cur);
        }
        else if(cur==')'){
            while(op.top()!='('){
                postfix.push_back(op.top());
                op.pop();
            }
            op.pop();
        }
        else if(op_list.find(cur)!=op_list.end()){
            if(op.empty())op.push(cur);
            else{
                if(priorities.at(cur)<=priorities.at(op.top())){
                    
                    while(!op.empty()){
                        if(op.top()=='(')break;
                        if(priorities.at(op.top())<priorities.at(cur))break;
                        postfix.push_back(op.top());
                        op.pop();
                    }
                    op.push(cur);
                }
                else op.push(cur);
            }
        }
    }

    while(!op.empty()){
        postfix.push_back(op.top());
        op.pop();
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>midfix;
    
    
    
    getPost();

    cout<<postfix;
}