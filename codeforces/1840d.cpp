#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

bool check(int g, vector<int> &a) {
    int cur = 0, cnt = 0;
    for (auto i : a) {
        if (i > cur) {
            cur = i+2*g;
            cnt++;
        } 
    }
    return cnt <= 3;
}

void Run() {
    int n; cin>>n;
    vector<int> a(n);
    for (auto& i : a) cin>>i;
    sort(a.begin(),a.end());
    int l = -1, r = 1e10, mid;
    while(r-l > 1) {
        mid = (l+r)>>1;
        if (check(mid,a)) r = mid;
        else l = mid;
    }
    cout<<r<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}
