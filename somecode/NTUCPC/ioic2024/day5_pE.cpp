#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, K, T;    
    cin>>N>>M>>K>>T;
    if (T) return 0;
    string S; cin>>S; 
    vector<int> a(N+1), b(N+1);
    for (int i = 1; i <= N; ++i) cin>>a[i];
    for (int i = 1; i <= N; ++i) cin>>b[i];
    
    return 0;
}
