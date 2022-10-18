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
    int m;
    while(cin>>m) {
        vector<int> r(m), b(m);
        for (auto& i : r) cin>>i;
        for (auto& i : b) cin>>i;
        sort(r.begin(),r.end());
        sort(b.begin(),b.end(),greater<int>());
        ll ans = 0;
        for (int i = 0; i < m; ++i) ans += (r[i]*b[i]);
        cout<<ans<<endl;
    }
    return 0;
}
