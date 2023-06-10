#include <iostream>

using namespace std;
const int MAX_SIZE = 100000;
int inorder[MAX_SIZE+1]={};
int postorder[MAX_SIZE]={};

int preorder[MAX_SIZE]={};

int n=MAX_SIZE;

void getPreorder(int is, int ie, int ps, int pe, int idx){
    
    if(ps>pe||is>ie||idx>=n)return;
    int node = postorder[pe];

    int left_size = inorder[node]-is;
    int right_size = ie-left_size;

    preorder[idx]=node;

    if(ps==pe||is==ie||idx==n-1)return;    

    getPreorder(is, is+left_size-1, ps, ps+left_size-1, idx+1);
    getPreorder(is+left_size+1, ie, ps+left_size, pe-1, idx+left_size+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int temp;
    for(int j=0; j<2; j++){
    for(int i=0; i<n; i++){
        cin>>temp;
        if(j==0){
            inorder[temp]=i;
        }
        else{
            postorder[i]=temp;
        }
    }}

    getPreorder(0, n-1, 0, n-1, 0);
    for(int i=0; i<n; i++){
        cout<<preorder[i]<<" ";
    }
}