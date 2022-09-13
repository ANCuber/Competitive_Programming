#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    void Initialize();
    int r[4] = {0,10,15,20};
    int p, n;
    while(true) {
        int cur = r[1]^r[2]^r[3];
        
        Take_Stone(,,p,n);
        r[p] -= n;
    }

    return 0;
}
