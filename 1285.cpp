#include <bitset>
#include <iostream>
#include <string>
#include <memory>


using namespace std;

class flips{

    bitset<400> table;
    bitset<400> rows[20];
    bitset<400> cols[20];
    int size;
    public:
    
        flips(int size, bitset<400> &table){
            this->table = std::move(table);
            this->size = size;
            rows[0] = (1 << size) - 1;
            for(int i=0; i<size; ++i){
                cols[0][20*i] = 1;

                
            }
            
            for(int i=1; i<20; ++i){
                rows[i] = rows[i-1] << 20;

                cols[i] = cols[i-1] << 1;
            }
        }

        flips &flipRow(int row){
            table ^= rows[row];
            return *this;
        }

        flips &flipCol(int col){
            table ^= cols[col];
            return *this;
        }

        flips print(){
            for(int i=0; i<this->size; ++i){
                for(int j=0; j<this->size; ++j)
                    cout<<table[20*i + j]<<" ";

                    cout<<"\n";
            }

            cout<<"\n";
            
            return *this;
        }

        size_t countRow(int row){
            return (table & rows[row]).count();
        }

        size_t countCol(int col){
            return (table & cols[col]).count();
        }

        bitset<400> operator[](const int &row){


            return this->table >> (20 * row);
        }

        size_t getSize(){
            return this->size;
        }
};

size_t answer = __UINT32_MAX__;

void dfs(int row, flips &table){
    
    if(row>=table.getSize())return;
    static int i=0;
    auto size = table.getSize();
    size_t Ts=0;
    for(size_t i = 0; i< size; ++i){
        auto num_T = table.countCol(i);
        Ts += min(num_T, size - num_T);
    }

    answer = min(answer, Ts);

    for(int nrow=row; nrow<size; ++nrow){
        table.flipRow(nrow);
        dfs(row+1, table);
        table.flipRow(nrow);
    }
}

void solve(){
    int N;
    cin>>N;

    string temp[N];

    for(auto &row : temp){
        cin>>row;
    }

    bitset<400> tb;

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(temp[i][j]=='H')
                tb[20*i + j] = 1;
        }
    }

    flips table(N, tb);

    dfs(0, table);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cout<<answer;
}