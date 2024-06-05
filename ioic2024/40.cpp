#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin>>N;  
    if (N == 1) {
        cout<<1<<endl;
        return 0;
    }
    vector<int> dg(N+2,0);
    for (int i = 1; i < N; ++i) {
        int a, b; cin>>a>>b;
        dg[a]++, dg[b]++;
    }
    cout<<*max_element(dg.begin(),dg.end())<<endl;
    return 0;
}
