#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <bitset>
#include <limits>
using namespace std;



vector<vector<complex<int>>> testCases;

double solve(vector<complex<int>> &arr){
    int n = arr.size();
    int m = n / 2;


    bitset<20> counter;

    int temp = (1 << m) - 1;

    double min = std::numeric_limits<double>::max();

    complex<double> val;


    for(;temp < (1 << n); ++temp){

        counter = temp;

        if(counter.count()!=m)continue;

        val = {0, 0};
        for(int i=0; i<n; ++i){
            if(counter[i])val-=arr[i];
            else val+=arr[i];
        }


        double mag = abs(val);

        min = mag > min ? min : mag;
    }
     

    return min;
}

int main(){
    int T;
    cin>>T;
    testCases.assign(T, vector<complex<int>>());

    for(int t=0; t<T; ++t){
        int N;
        cin>>N;

        testCases[t].assign(N, complex<int>{0, 0});
        int r, i;
        for(int n=0; n<N; ++n){
            cin>>r>>i;

            testCases[t][n] = {r, i};
        }
    }

    cout<<fixed;
    cout.precision(12);
    for(int t=0; t<T; ++t){
        cout<<solve(testCases[t])<<"\n";
    }
}