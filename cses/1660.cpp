#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; ll x;
    cin>>n>>x;
    queue<ll> q;
    ll sum = 0;
    int cnt = 0;
    while(n--) {
        ll a; cin>>a;
        sum += a;
        q.push(a);
        while(!q.empty() && sum > x) {
            sum -= q.front();
            q.pop();
        }
        if (sum == x) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
