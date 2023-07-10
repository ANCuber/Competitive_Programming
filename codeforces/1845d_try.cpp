#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void Run() {
    int n; cin>>n;
    vector<int> a(n);
    for (auto& i : a) cin>>i;
    for (int k = -5; k <= 10; ++k) {
        int tmp = 0;
        for (auto i : a) {
            if (tmp >= k && tmp+i < k) tmp = k;
            else tmp += i;
        }
        cout<<tmp<<" ";
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}
