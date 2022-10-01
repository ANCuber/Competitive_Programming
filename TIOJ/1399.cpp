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
#define int long long

struct my{
    int first, second, flag;
    bool operator<(my b) {
        if (first == b.first) return second<b.second;
        return first<b.first;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n;
    while(cin>>t>>n) {
        p_q <int> pq;
        vector<int> f(n), d(n);
        for (int i = 0; i < n; ++i) cin>>f[i];
        for (int i = 0; i < n; ++i) cin>>d[i];
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int a; cin>>a;
            t -= a;
            
        }
        cout<<ans<<endl;
    }
    return 0;
}
