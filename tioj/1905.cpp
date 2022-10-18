#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

const int MAXN = 1e5;

struct Nd{
    int sum, lmx, rmx, mx;
};

struct SEG{
    int n;
    vector<Nd> d;
    void init(int _n) {
        n = _n;
        d.resize((n<<1)+5);
        int pr=0, nw;
        for (int i = 0; i < n; ++i) {
            cin>>nw;
            d[i+n] = {nw-pr,nw-pr,nw-pr,nw-pr};
            pr = nw;
        }
        for (int i = n-1; i > 0; --i) {
            
        }
    }
    int query() {
        
    }
} seg;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;
    seg.init(n);
    while(q--) {
        
    }
    return 0;
}
