#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, ln, w;
    cin>>n>>ln>>w;
    vector< pii > p(n);

    for (int i = 0; i < n; ++i) cin>>p[i].first>>p[i].second;
    sort(p.begin(),p.end());

    int ci, ans = 0;
    int l, r, d, u;

    for (int i = 0; i < n; ++i) {
        ci = i;
        l = p[i].first, r = l+w;
        vector < pii > pts;
        while(ci < n && p[ci].first <= r) {
            if (p[ci].second <= p[i].second+ln && p[ci].second >= p[i].second-ln) {
                pts.push_back({p[ci].second,p[ci].first});
            }
            ci++;
        }
        sort(pts.begin(),pts.end());
        queue <int> q;
        for (int j = 0; j < pts.size(); ++j) {
            u = pts[j].first, d = u-ln;
            while(!q.empty() && q.front() < d) q.pop();
            q.push(u);
            int sz = q.size();
            ans = max(ans,sz);
        }
    }
    cout<<ans<<endl;

    return 0;
}
