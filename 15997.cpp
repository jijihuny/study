#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


struct game{
    string team_first;
    string team_second;
    vector<float> prob;
};

vector<game> games;

map<string, int> points;

float prob_next_round[4]={};

void dfs(vector<game>::iterator cur_game){
    

    auto now_game = *cur_game;
    pair<int, int> winning_points;
    for(int i=0; i<3; ++i){
        if(now_game.prob[i]==0)continue;

        if(i==0){
            winning_points={3, 0};
        }
        else if(i==1){
            winning_points={1, 1};
        }
        else{
            winning_points={0, 3};
        }

        points[now_game.team_first]+=winning_points.first;
        points[now_game.team_second]+=winning_points.second;
        
        dfs(cur_game+1);

        points[now_game.team_first]-=winning_points.first;
        points[now_game.team_second]-=winning_points.second;
    }
}