#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'
#define int long long

struct val{
    int c, h;
    bool operator<(val b) {
        if (c == b.c) return h > b.h;
        return c < b.c;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t; cin>>n>>t;
    vector<val> hg;
    vector<int> lw;
    hg.push_back({0,0});
    
    for (int i = 0; i < n; ++i) {
        int c, h; cin>>c>>h;
        if (h <= c-h) {
            lw.push_back(h);
            lw.push_back(c-h);
        } else {
            hg.push_back({c,h});
        }
    }
    sort(lw.begin(),lw.end());
    sort(hg.begin(),hg.end());

    vector<int> s(hg.size(),0);
    for (int i = 1; i < lw.size(); ++i) lw[i] += lw[i-1];
    for (int i = 1; i < hg.size(); ++i) s[i] = s[i-1]+hg[i].c;

    vector<int> mn(hg.size(),0), mx(hg.size(),0);
    mn[hg.size()-1] = hg[hg.size()-1].h; mx[1] = hg[1].c-hg[1].h;
    for (int i = hg.size()-2; i > 0; --i) mn[i] = min(mn[i+1],hg[i].h);
    for (int i = 2; i < hg.size(); ++i) mx[i] = max(mx[i-1],hg[i].c-hg[i].h);

    int ans = 0;
    
    for (int i = 0; i < hg.size(); ++i) {
        int cur = t-s[i];
        if (cur < 0) break;
        ans = max(ans,i*2+(upper_bound(lw.begin(),lw.end(),cur)-lw.begin()));
    }
    for (int i = 1; i < hg.size(); ++i) {
        int cur = t-s[i];
        cur += mx[i];
        if (cur < 0) break;
        ans = max(ans,i*2-1+(upper_bound(lw.begin(),lw.end(),cur)-lw.begin()));
    }
    for (int i = 0; i < hg.size()-1; ++i) {
        int cur = t-s[i];
        cur -= mn[i+1];
        if (cur < 0) break;
        ans = max(ans,i*2+1+(upper_bound(lw.begin(),lw.end(),cur)-lw.begin()));
    }
    cout<<ans<<endl;
    return 0;
}
