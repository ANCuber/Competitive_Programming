#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

int n, Q, k;
int l = 1, r = 0;
int cur = 0;
vector<int> a;
vector<int> cnt(1e5+5,0), am(1e5+5,0);

struct query{
    int ql, qr, id;
    bool operator<(query b) {
        if (ql/k == b.ql/k) return qr < b.qr;
        return ql/k < b.ql/k;
    }
};

void sub(int v) {
    am[cnt[v]]--;
    cnt[v]--;
    am[cnt[v]]++;
    if (cur==cnt[v]+1 && am[cnt[v]+1]==0) cur = cnt[v];
}

void add(int v) {
    am[cnt[v]]--;
    cnt[v]++;
    am[cnt[v]]++;
    cur = max(cur,cnt[v]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>Q;
    k = n/sqrt(Q);
    a.resize(n+1);
    vector<query> q(n);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    for (int i = 0; i < Q; ++i) {
        cin>>q[i].ql>>q[i].qr;
        q[i].id = i;
    }
    sort(q.begin(),q.end());
    vector<int> ans(Q);
    am[0] = n;
    for (auto i : q) {
        while (r < i.qr) add(a[++r]);
        while (r > i.qr) sub(a[r--]);
        while (l < i.ql) sub(a[l++]);
        while (l > i.ql) add(a[--l]);
        ans[i.id] = cur;
    }
    for (int i = 0; i < Q; ++i) {
        cout<<ans[i]<<endl;
    }
    return 0;
}

