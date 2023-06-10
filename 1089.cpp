#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <tuple>
using namespace std;


vector<vector<vector<bool>>> LED(5, vector<vector<bool>>(3, vector<bool>(10, 0)));

vector<string> numbers = {"###...#.###.###.#.#.###.###.###.###.###",
                          "#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
                          "#.#...#.###.###.###.###.###...#.###.###",
                          "#.#...#.#.....#...#...#.#.#...#.#.#...#",
                          "###...#.###.###...#.###.###...#.###.###"};

vector<string> input;

vector<pair<int, int>> p;

void fillLED(void){
    for(int row=0; row<5; ++row){
        for(int col=0; col<3; ++col){
            for(int n=0; n<10; ++n){
                if(numbers[row][col+n*4]=='.'){
                    LED[row][col][n]=true;
                }
            }
        }
    }
}

void solve(void){
    int N = (input.front().size()+1) / 4;

    p.assign(N, {0, 0});

    bool visited[10]={};

    for(int n=0; n<N; ++n){
        fill_n(visited, 10, 0);
        for(int row=0; row<5; ++row){
            for(int col=0; col<3; ++col){
                if(input[row][col + n*4]=='#'){
                    for(int check=0; check<10; ++check){
                        if(LED[row][col][check])visited[check]=true;
                    }
                }
            }
        }

        for(int i=0; i<10; ++i){
            if(visited[i])continue;

            p[n].first += i;
            ++(p[n].second);
        }
    }

    int sum=0, x;
    std::tie(x, sum)=
    accumulate(p.begin(), p.end(), pair<int, int>{0,0}, [](auto &a, auto &b){
        return {0, a.second + b.second};
    });


    
}