#include <iostream>
#include <vector>

using namespace std;

vector<int> A[500000];
vector<int> sorted[500000];
void merge(vector<int> list[], int left, int mid, int right){
    int i=left;
    int j=mid+1;

    int k=left;

    while(i<=mid && j<=right){
        if(list[i][0]<=list[j][0]){
            sorted[k++][0] = list[i++][0];
            
        }
        else{
            sorted[k][0] = list[j][0];
            sorted[k++][1]
        }
    }
}