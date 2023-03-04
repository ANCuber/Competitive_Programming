#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, k;

bool check(int m, vector<int> &a) {
    int cs = 0, cnt = 1;
    for (auto i : a) {
        if (i > m) return 0;
        if (cs+i > m) {
            cs = 0;
            cnt++;
        } 
        cs += i;
    }
    return cnt <= k;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    vector<int> a(n);
    for (auto& i : a) cin>>i;
    int l = 0, r = 1e15;
    int mid = (l+r)>>1;
    while(r-l > 1) {
        if (check(mid,a)) r = mid;
        else l = mid;
        mid = (l+r)>>1;
    }
    cout<<r<<endl;
    return 0;
}
