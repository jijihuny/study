#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;



vector<int> PrimeNumbers;

int P_candidates[45001]={0};





int cnt(int m, vector<int>::iterator start, vector<int>::iterator end, long long prev=1,  int recur=0){
    int res=0;
    long long temp;
    for(auto i=start; i!=end; i++){
        temp = *i;
        if(m < (prev * (*i)) || prev * (*i) <=0)break;
        

        res += m / ((*i) * prev);
        res -= cnt(m, i+1, end, prev * (*i), recur+1);
    }
    
    if(recur==0)return m-res;

    else return res;
}

bool checker(int m, vector<int>::iterator p){
    
    for(auto i=PrimeNumbers.begin(); i!=p; i++){
        if(m%(*i)==0)return false;
    }
    return true;
}

pair<int, bool> Discriminator(int m, int k, vector<int>::iterator p){

    return {cnt(m, PrimeNumbers.begin(), p), checker(m, p)};
}

int Kth_Number(const int start, const int end, const int K){


    int mid = start/2 + end/2;
    auto P = upper_bound(PrimeNumbers.begin(), PrimeNumbers.end(), mid);
    auto res = Discriminator(mid, K, P);
    // cout<<"mid: "<<mid<<"res: "<<res.first<<"bool :"<<res.second<<"K: "<<K<<"P: "<<P-PrimeNumbers.begin()<<'\n';
    if(res.first>K)return Kth_Number(start, mid, K);
    else if(res.first<K)return Kth_Number(mid+1, end, K);
    else{
        if(res.second==true)return mid;
        else{
            while(!checker(--mid, P));
            return mid;
        }
    }
}


int main(){
    cin.tie(NULL)->sync_with_stdio(false);

    for(int i=2; i<=45000; i++){
        if(P_candidates[i]==1){
            continue;
        }
        PrimeNumbers.push_back(i*i);
        for(int j = i*i; j<=45000; j+=i){
            P_candidates[j]=1;
        }
    }
    
    //cout<<PrimeNumbers[0];

    int K;

    cin>>K;
    
    cout<<Kth_Number(K, 2*K, K)<<'\n';

    // cout<<*lower_bound(PrimeNumbers.begin(), PrimeNumbers.end(), 1000000000);
    //cnt(K, PrimeNumbers.begin(), PrimeNumbers.begin()+224);

}