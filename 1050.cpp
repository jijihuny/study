#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;



typedef unordered_map<string, int> Elem;
typedef unordered_map<string, Elem> Form;

Elem list;
Form form;

void getInput(){
    int N, M;
    cin>>N>>M;
    string temp_name;
    int temp_cost=0;
    for(int i=0; i<N; ++i){
        cin>>temp_name>>temp_cost;

        list.insert({temp_name, temp_cost});
    }
    string temp_form;
    for(int i=0; i<M; ++i){
        cin>>temp_form;

        
    }
}