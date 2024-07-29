#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mid ((l+r)>>1)

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin>>n>>m>>k;
    long double sum = 0;
    set<int> s;
    map<long double,int> mp;
    map<int,long double> rv;
    for (int i = 0; i < m; ++i) {
        int f; cin>>f;
        s.insert(f);
        sum += f;
    }
    long double exp = sum/(1.0*m);
    int cnt = 0;
    for (auto i : s) {
        mp[i] = ++cnt;
        rv[cnt] = i;
    }
    int bnd = 0;
    for (; bnd <= cnt; ++bnd) if (rv[bnd] > exp) break;
    bnd--;
    vector<long double> arr(cnt+5,0);
    for (int i = 1; i <= n; ++i) {
        int v; cin>>v;
        arr[mp[v]]++;
    }
    for (int i = 0; i < 2; ++i) {
        if (i&1) {
            long double sm = 0;
            for (int j = bnd+1; j <= cnt; ++j) sm += arr[j];
            for (int j = bnd+1; j <= cnt; ++j) arr[j] = 0;
            sm = sm/(1.0*m);
            for (int j = 1; j <= cnt; ++j) arr[j] += sm;

        } else {
            long double sm = 0;
            for (int j = 1; j <= bnd; ++j) sm += arr[j];
            for (int j = 1; j <= bnd; ++j) arr[j] = 0;
            sm = sm/(1.0*m);
            for (int j = 1; j <= cnt; ++j) arr[j] += sm;
        }
        for (int i = 1; i <= cnt; ++i) cout<<arr[i]<<' '; cout<<endl;

    }
    //for (int i = 1; i <= cnt; ++i) cout<<arr[i]<<' '; cout<<endl;
    if (k <= 2) {
        long double A = 0;
        for (int i = 1; i <= cnt; ++i) A += arr[i]*rv[i];
        cout<<A<<'\n';
        return 0;
    }
    long double L = 0, R = 0;
    for (int i = 1; i <= bnd; ++i) L += arr[i];
    for (int i = 1; i <= bnd; ++i) R += arr[i];

    for (int i = 2; i < k; ++i) {
        if (i&1) {
            long double C = R/(1.0*m);
            R = C;
            L += C;
        } else {
            long double C = L/(1.0*m);
            L = C;
            R += C;
        }
        cout<<L<<' '<<R<<endl;
    }
    long double ans = 0;
    for (int i = 1; i <= cnt; ++i) {
        if (i <= bnd) ans += rv[i]*L;
        else ans += rv[i]*R;
    }
    cout<<fixed<<setprecision(15)<<ans<<'\n';
    return 0;
}
