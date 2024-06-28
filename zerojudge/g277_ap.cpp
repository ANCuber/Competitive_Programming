#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

priority_queue<pair<int,int> > pq;

int solve(vector<ll> &prs, int L, int R) {
    if (L == R) return L;
    while(pq.top().second < L || pq.top().second > R) pq.pop();
    int cur = pq.top().second;
    if (prs[R]-prs[cur] >= prs[cur-1]-prs[L-1]) return solve(prs,cur+1,R);
    else return solve(prs,L,cur-1);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    vector<int> a(n+2);
    vector<ll> prs(n+2,0);
    for (int i = 1;i <= n; ++i) {
        cin>>a[i];
        pq.push({-a[i],i});
        prs[i] = prs[i-1]+(ll)a[i];
    }
    cout<<a[solve(prs,1,n)]<<'\n';
    return 0;
}
