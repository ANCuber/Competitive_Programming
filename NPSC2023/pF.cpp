#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M, K, X;    
    cin>>N>>M>>K>>X;
    vector<int> a(N+5), b(M+5);
    for (int i = 1; i <= N; ++i) cin>>a[i];
    map<int,int> mp;
    for (int i = 1; i <= M; ++i) {
        cin>>b[i];
        mp[b[i]]++;
    }
    int P = M, ans = 0;
    for (int i = 0; i <= N; ++i) {
        if (i) mp[a[i]]++;
        while(P && mp.size() > X) {
            mp[b[P]]--;
            if (!mp[b[P]]) mp.erase(b[P]);
            P--;
        }
        if (mp.size() <= X) ans = max(ans,i+P);
    }
    cout<<ans<<'\n';
    return 0;
}
