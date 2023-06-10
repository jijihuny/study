#include <iostream>

using namespace std;


int R1[4]={};
int R2[4]={};


int points[4][4]={};

void fill_Rs(){
    R1[0]=max(points[0][0], points[3][0]);
    R1[2]=min(points[0][2], points[3][2]);
    R1[1]=max(points[0][1], points[1][1]);
    R1[3]=min(points[0][3], points[1][3]);

    R2[0]=max(points[1][2], points[2][2]);
    R2[2]=min(points[1][0], points[2][0]);
    R2[1]=max(points[2][3], points[3][3]);
    R2[3]=min(points[2][1], points[3][1]);
}

bool is_in_R(int x, int y, int* R){
    return (x <= R[2] && x >= R[0]) && (y <= R[3] && y >= R[1]);
}

size_t count_squares(){
    int x1=R1[0], x2=R1[2];
    int y1=R1[3], y2=R1[1];

    while(x1!=x2 && y1!=y2){
        if(y1-R2[3]==x1-R2[0])break;

        if(x1!=R1[2])++x1;
        else if(y1!=R1[1])++y1;
    }
    while(x1!=x2 && y1!=y2){
        if(y2-R2[1] == x2-R2[2])break;

        if(y2!=R1[3])++y2;
        else if(x2!=R1[0])++x2;
    }

    
}


int main(){

    cin.tie(NULL)->sync_with_stdio(false);

    int T;
    cin>>T;

    size_t res[T];

    for(int i=0; i<T; ++i){
        for(int j=0; j<4; ++j){
            for(int k=0; k<4; ++k){
                cin>>points[j][k];
            }
        }

        fill_Rs();

        // for(auto i : R1)cout<<i<<" ";
        // cout<<"\n";
        // for(auto i : R2)cout<<i<<" ";
        // cout<<"\n";

        res[i]=count_squares();
    }

    for(auto i : res)cout<<i<<'\n';
}