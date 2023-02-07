#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, c, d; cin>>a>>b>>c>>d;
    a %= 10007, b %= 10007, c %= 10007, d %= 10007;
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < 10007; ++i) {
        int sum = (d+c*i+b*i*i+a*i*i*i)%10007;
        if (!sum) {
            ans.pb(i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for (auto i : ans) cout<<i<<endl;
    
    return 0;
}
