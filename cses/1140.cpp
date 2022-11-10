#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int long long

const int maxn = 2e5;

struct Pro {
    int st, ed; 
    ll p;
    bool operator<(Pro b) {
        return st < b.st;
    }
} tsk[maxn+5];

set<int> num;
map<int,int> mp;

struct BIT {
    vector<int> a;
    int sz;
    void init(int cnt) {
        a.assign(cnt+5,0);
        sz = cnt;
    }
    void upd(int p, int v) {
        while(p <= sz) {
            a[p] = max(a[p],v);
            p += p&-p;
        }
    }
    int mx(int p) {
        int ret = 0;
        while(p > 0) {
            ret = max(ret,a[p]);
            p -= p&-p;
        }
        return ret;
    }
} bit;

int n, a, b, c;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    scanf("%lld",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld%lld",&a,&b,&c);
        tsk[i] = {a,b,c};
        num.insert(a), num.insert(b);
    }
    
    int cnt = 0;
    for (int i : num) mp[i] = ++cnt;
    for (int i = 1; i <= n; ++i) tsk[i] = {mp[tsk[i].st],mp[tsk[i].ed],tsk[i].p};
    
    sort(tsk+1,tsk+n+1);
    bit.init(cnt);
    
    vector<int> dp(n+1,0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = bit.mx(tsk[i].st-1)+tsk[i].p;
        bit.upd(tsk[i].ed,dp[i]);
    }
    int ans = *max_element(dp.begin(),dp.end());
    printf("%lld\n",ans);
    return 0;
}
