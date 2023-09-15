#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

struct Line{
    int p, h;
    bool operator<(Line y) {
        return abs(p) < abs(y.p);
    }
};

void Run(int n) {
    vector<int> Bld;
    for (int i = 0; i < n; ++i) {
        int L, H, R; cin>>L>>H>>R;
        Bld.pb({L,H});
        Bld.pb({-R,H});
    }
    sort(Bld.begin(),Bld.end());
    multiset<int> ms;
    for (auto [p,h] : Bld) {
        if (p > 0) {
            
        } else {
            
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    while(cin>>N && N) Run(N);
    return 0;
}
