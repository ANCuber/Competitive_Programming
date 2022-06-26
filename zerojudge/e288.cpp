#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ll code(char c) {
    if (c-'a' >= 0) return c-'a'+26;
    return c-'A';
}//A,B,C...Z,a,b,c...z

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n; cin>>m>>n;
    unordered_multiset<ll> mp;
    for (int i = 0; i < n; ++i) {
        ll sc = 0;
        string a; cin>>a;
        for (int j = 0; j < a.size(); ++j) {
            sc = sc|(1LL<<(code(a[j])));
        }
        mp.insert(sc);
    }
    ll comp = (1LL<<m)-1;
    ll ans = 0;
    for (auto i : mp) {
        ll opp = comp^i;
        ans += mp.count(opp);
    }
    ans >>= 1;
    cout<<ans<<endl;
    return 0;
}