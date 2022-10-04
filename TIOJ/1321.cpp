#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const ll mod = 1e15+7, pivot = 31;

ll pow(ll x, int n) {
    ll base = x, ans = 1;
    while(n) {
        if (n&1) ans = ans*base%mod;
        base = base*base%mod;
        n >>= 1;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s; cin>>s;        
    s = "0"+s;
    int sz = s.size();
    ll ls = 0, rs = 0, base = 1;
    vector<int> a(sz,0);
    for (int i = 1;i <= sz; ++i) {
        a[i] = a[i-1]+(s[i]-'a')*base;
        if (a[i] >= mod) a[i] -= mod;
        base *= pivot;
        if (base >= mod) base -= mod;
    }
    for (int i = 0; i < sz; ++i) {
        int ls, rs;
        if ((sz+1)/2+i <= sz) ls = ((a[(sz+1)/2+i]-a[i])*pow(pow(pivot,i),mod-2)+mod)%mod;
        else ls = ((a[sz]-a[i])*pow(pow(pivot,i),mod-2)+mod)%mod+pow(pivot,(sz+1)/2-sz+i)*a[(sz+1)/2-sz+i];
        
    }

    return 0;
}
