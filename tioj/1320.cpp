#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<int> h(n+2), L(n+2), R(n+2);
    map<int,int> mp;
    for (int i = 1; i <= n; ++i) cin>>h[i];
    h[0] = h[n+1] = 1e9+5;
    
    mp[1] = *min_element(h.begin()+1,h.begin()+n+1);
    stack<int> stk, stk2;
    stk.push(0), stk2.push(n+1);
    for (int i = 1; i <= n; ++i) {
        while(!stk.empty() && h[stk.top()] <= h[i]) stk.pop();
        L[i] = stk.top();
        stk.push(i);
    }
    for (int i = n; i >= 1; --i) {
        while(!stk2.empty() && h[stk2.top()] <= h[i]) stk2.pop();
        R[i] = stk2.top();
        stk2.push(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (mp.count(R[i]-L[i]-1)) mp[R[i]-L[i]-1] = min(mp[R[i]-L[i]-1],h[i]);
        else mp[R[i]-L[i]-1] = h[i];
    }
    
    int q; cin>>q;
    int mn = 1e9+7;
    for (auto iter = mp.end(); ; --iter) {
        if (iter == mp.end()) iter--;
        if (mn < iter->second) {
            iter->second = mn;
        } else {
            mn = iter->second;
        }
        if (iter == mp.begin()) break;
    }
    while(q--) {
        int x; cin>>x;
        auto iter = mp.lower_bound(x);
        cout<<iter->second<<endl;
    }
    return 0;
}

