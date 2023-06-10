#include <iostream>
#include <vector>
using namespace std;


int map[10][10]={};



int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M;
void getMap(){

    cin>>N>>M;

    int island_id=1;
    bool flag=0;
    for(int row=0; row<N; ++row){
        for(int col=0; col<M; ++col){
            cin>>flag;

            if(flag){
                int temp_id=0;

                for(int i=0; i<4; ++i){
                    int nx=col+dx[i], ny=row+dy[i];

                    if(nx<0 || ny<0)continue;

                    if(map[ny][nx]){
                        temp_id=map[ny][nx];
                        break;
                    }
                }

                if(temp_id)map[row][col]=temp_id;
                else map[row][col]=island_id++;
            }
        }
    }
}






