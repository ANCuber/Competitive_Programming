#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int maxn = 2e5+5;
vector<int> v(maxn,0);

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    int cnt = 0;
    while(n--) {
        int x; cin>>x;
        if (!v[x-1]) {
            v[x] = ++cnt;
        } else {
            v[x] = v[x-1];
        }
    }
    cout<<cnt<<endl;
    return 0;
}
