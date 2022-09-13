#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int n, m, k, ch, now = 0;

struct BIT{
    vector<bool> bs;
    void init() {
        bs.assign(1e6+5,0);
    }
    void add(int p) {
        while(p <= n) {
            bs[p] = bs[p]^1;
            p += p&-p;
        }
    }
    int sum(int p) {
        int ret = 0;
        while(p > 0) {
            ret ^= bs[p];
            p -= p&-p;
        }
        return ret;
    }
} bit;

void dfs(vector<vector<int> > &g, vector<int> &in, vector<int> &out, int p) {
    in[p] = ++now;
    for (auto i : g[p]) {
        dfs(g,in,out,i);
    }
    out[p] = now;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    vector<vector<int> > g(n+1);
    vector<int> in(n+1), out(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>k;
        while(k--) {
            cin>>ch;
            g[i].push_back(ch);
        }
    }
    bit.init();
    dfs(g,in,out,1);
    int a, b;
    while(m--) {
        cin>>a>>b;
        if (a) {
            cout<<bit.sum(in[b])<<endl;
        } else {
            bit.add(in[b]);
            bit.add(out[b]+1);
        }
    }
    return 0;
}
