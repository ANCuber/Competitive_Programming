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
    sort(p.begin(),p.end);

    int ci, can;
    int ans = 0;
    int l, r, d, u;

    for (int i = 0; i < n; ++i) {
        ci = i, can = 0;
        l = p[i].first, r = l+w;
        d = p[i].second, u = d+ln;
        while(p[ci].first <= r) {
            
        }
        
    }

    return 0;
}
