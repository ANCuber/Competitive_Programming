#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

int n, k, flg;
vector<int> dp(1e6+5,0), mx(1e6+5,0), ext(1e5+5,0), mxcnt(1e6+5,0), cnt(1e6+5,0);
deque<int> q;

int aliens(vector<int> &a, int p, int tag) {
    fill(dp.begin(),dp.end(),0);
    fill(mx.begin(),mx.end(),-2e18);
    fill(ext.begin(),ext.end(),0);
    fill(mxcnt.begin(),mxcnt.end(),0);
    fill(cnt.begin(),cnt.end(),0);
    
    int L = 1;
    q.clear();
    
    for (int i = 1; i <= n; ++i) {
        while (ext[a[i]]) ext[a[L++]] = 0;
        ext[a[i]] = 1;
        
        if (mx[L-1] < 0) {
            dp[i] = (i-(L-1))-p;
            cnt[i] = 1;
        } else {
            dp[i] = mx[L-1]+(i-(L-1))-p;
            cnt[i] = mxcnt[L-1]+1;
        }
        
        while(!q.empty() && q.front() < L) q.pop_front();
        if (!q.empty() && ((dp[q.front()]+(i-q.front())-p > dp[i]) || ((dp[q.front()]+(i-q.front())-p == dp[i]) && cnt[q.front()]+1 < cnt[i]))) {
            dp[i] = dp[q.front()]+(i-q.front())-p;
            cnt[i] = cnt[q.front()]+1;
        }
        while(!q.empty() && ((dp[q.back()] < dp[i]-(i-q.back()) || (dp[q.back()] == dp[i]-(i-q.back()) && cnt[q.back()] >= cnt[i])))) q.pop_back();
        q.push_back(i);
        
        if (dp[i] > mx[i-1] || (dp[i] == mx[i-1] && cnt[i] < mxcnt[i])) {
            mx[i] = dp[i];
            mxcnt[i] = cnt[i];
        } else {
            mx[i] = mx[i-1];
            mxcnt[i] = mxcnt[i-1];
        }
    }
    flg = mxcnt[n];
    if (tag) return mx[n];
    if (mxcnt[n] <= k) return 1;
    else return 0;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k;
    vector<int> a(n+2);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    int l = -1, r = 1e6+5, mid;
    while(r-l > 1) {
        mid = (l+r)>>1;
        if (aliens(a,mid,0)) r = mid;
        else l = mid;
    }
    cout<<aliens(a,r,1)+r*k<<'\n';
    return 0;
}
