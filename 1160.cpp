#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long bigint;

unordered_map<bigint, bigint> power;

bigint m, a, c, x0, n, g;

bigint power_(bigint x, bigint b) {
    if(b == 0) return 1L;

    if(b == 1) return x % g;

    if(power.find(b)!=power.end()) {
        return power[b];
    }

    else {

        return power[b] = (power_(a, b / 2) * power_(a, b % 2 == 1 ? b / 2 + 1 : b / 2)) % g;
    }
}

int main() {
    
    cin>> m >> a >> c >> x0 >> n >> g;


    cout << power_(a, n) * x0 + c * ((power_(a, n) - 1) / (a - 1));
}