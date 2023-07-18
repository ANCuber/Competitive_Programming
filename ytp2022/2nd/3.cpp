#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    int ans = 0, id = 1, a;
    for (int i = 1; i <= n; ++i) {
        cin>>a;
        if (a < id) id = a;
        ans = max(ans,id);
        if (a >= id) id++;
    }
    cout<<ans<<endl;
    return 0;
}
