#include <iostream>
using namespace std;


int main(){


    int i=0;
    int A[3]={3, 5, 8};
    A[i] = ++i;
    for(auto k : A)cout<<k<<" ";
    i=0;
    A[++i] = i;
    for(auto k : A)cout<<k<<" ";
}