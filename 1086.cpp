#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string.h>
#include <bitset>
#include <cmath>


using namespace std;

uint64_t decimal_mod[751]={};

char input_list[15][51];

char input_buffer[2][51];
char *cof;

vector<uint64_t> A;
vector<uint64_t> A_len;

void fill_dec(uint64_t K){
    decimal_mod[0] = 1 % K;
    for(int i=1; i<751; i++){
        decimal_mod[i] = (decimal_mod[i-1] * 10)%K;
    }
}

uint64_t f_k(uint64_t K){
    uint64_t sum=0;
    for(int i=0; i<50; i++){
        sum+=decimal_mod[i]*(uint64_t)(cof[49-i]!=0?cof[49-i]-'0':0);
        
    }
    
    return (sum % K);
}

void GetNumToBuf(uint8_t idx, uint16_t K){

    copy(input_list[idx], input_list[idx]+51, input_buffer[1]);

    uint16_t len = strlen(input_buffer[1]);

    cof = input_buffer[0]+len+1;

    // for(int i=0; i<50; i++)cout<<cof[i]<<" ";
    A.push_back(f_k(K));
    A_len.push_back(len);
}

uint64_t dp[(1<<15)][100]={};
uint16_t dec_size[(1<<15)]={};
bitset<15> checker;

void fill_dp(uint64_t N, uint64_t K){
    for(uint32_t idx=1; idx<(1<<N); idx++){
        if(__builtin_popcount(idx)==1){
            uint8_t key=0;
            while(!(idx&(1<<key)))key++;
            ++dp[idx][A.at(key)];
            dec_size[idx]=A_len.at(key);
            
        }
        else{
            for(uint32_t i=1; i<idx; i=i<<1){
                if(idx&i){    
                    // cout<<i<<" ";   
                    for(uint32_t j=0; j<K; j++){
                        if(dp[i][j]!=0){
                            // cout<<j<<" ";
                            for(uint32_t k=0; k<K; k++){
                                if(dp[idx&(~i)][k]!=0){
                                    // cout<<k<<" ";
                                    dp[idx][(j*decimal_mod[dec_size[idx&(~i)]] + k)%K]+=dp[i][j]*dp[idx&(~i)][k];
                                }
                            }
                        }
                    }
                    checker=i;

                    dec_size[idx] += A_len.at(checker._Find_first());
                }
                // cout<<'\n';
            }
        }
    }
    
}



int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    int N;
    cin>>N;

    for(int i=0; i<N; i++){
        cin>>input_list[i];
    }

    int K;
    cin>>K;

    fill_dec(K);

    for(int i=0; i<N; i++){
        GetNumToBuf(i, K);
    }
    
    // for(auto i:A)cout<<i<<" ";
    // cout<<"\n";
    // for(auto i:A_len)cout<<i<<" ";

    fill_dp(N, K);
    // cout<<0;
    if(dp[(1<<N)-1][0]==0){cout<<0<<"/"<<1;return 0;}

    uint64_t r=1;
    for(int i=1; i<N+1; i++){
        r *= i%dp[(1<<N)-1][0];
        r %= dp[(1<<N)-1][0];
    }

    

    auto d = (r==0)?dp[(1<<N)-1][0]:__gcd(r, (uint64_t)dp[(1<<N)-1][0]);

    dp[(1<<N)-1][0] /= d;


    
    auto devisor = [&]{
        uint64_t res=1;
        for(int i=2; i<=N; i++){
            res*=i;
        }
        return res/d;
    };
    
    cout<<dp[(1<<N)-1][0]<<"/"<<devisor();
    // cout<<res.first<<"/"<<res.second;
    // for(auto i: A)cout<<i<<" ";
}