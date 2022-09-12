#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int n, m, k, u, v, c;

int ff(int x, vector<int> &fa) {
    if (x == fa[x]) return x;
    return fa[x] = ff(fa[x],fa);
}

int slv(vector<int> fa, vector<pair<int, pii > > &e) {
    int cnt = 0;
    for (auto i : e) {
        pii cur = i.second;
        if (ff(cur.first,fa)== ff(cur.second,fa)) {
            continue;
        } else {
            cnt += i.first;
            fa[ff(cur.first,fa)] = ff(cur.second,fa);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m>>k;
    vector<int> fa(n+1);
    vector<pair<int, pii > > e(m);
    for (int i = 0; i <= n; ++i) fa[i] = i;
    for (int i = 0; i < m; ++i) {
        cin>>u>>v>>c;
        e[i] = {c,{u,v}};
    }
    int mx, mn;
    sort(e.begin(),e.end());
    mn = slv(fa,e);
    sort(e.begin(),e.end(),greater<pair<int, pii > >());
    mx = slv(fa,e);
    //cout<<mx<<' '<<mn<<endl;;
    if (k <= mx && k >= mn) cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;
    return 0;
}
