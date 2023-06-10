#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string characters;

string newstring;

vector<int> stack;

string bomb;

string::iterator find_bomb(){
    string::iterator there=newstring.begin();

    for(auto cur:characters){
        
        if(cur==bomb.at(0)){
            stack.push_back(1);
        }
        else if(!stack.empty()){
            if(cur==bomb.at(stack.back())){
                ++stack.back();
            }
            else{
                while(!stack.empty())
                    stack.pop_back();
            }
        }
        if(!stack.empty())      
            if(bomb.size()==stack.back()){
                there-=bomb.size()-1;
                stack.pop_back();
                continue;
            }
        *(there++)=cur;

    }

    return there;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>characters;
    cin>>bomb;
    
    copy(characters.begin(), characters.end(), newstring.begin());
    auto end = find_bomb();


    if(newstring.begin()==end)cout<<"FRULA";
    else
    for(auto i=newstring.begin(); i!=end; i++)cout<<*i;
}