#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n; 
    vector<int> v(200010,0);
    for (int i = 0; i < n; ++i) {
        int x; cin>>x;
        v[x]++;
    }
    int cnt = 0;
    for (int i = 0; i <= 200005; ++i) {
        if (v[i]&1) cnt++;
        v[i+1] += v[i]/2;
    }
    if (n != 1 && cnt <= 2) cout<<"Y"<<endl;
    else cout<<"N"<<endl;
    
    return 0;
}
