#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, w;

bool slv(int g, vector<int> &s) {
    int cnt = 0, sum = 0;
    for (auto i : s) {
        if (i > g) return 0;
        if (sum+i > g) {
            sum = i;
            cnt++;
        } else {
            sum += i;
        }
    }
    return cnt <= w;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n>>w && (n+w)) {
        vector<int> s(n);
        for (auto& i : s) cin>>i;
        int l = 0, r = 1e6+5;
        int mid = (l+r)>>1;
        while(r-l>1) {
            if (slv(mid,s)) r = mid;
            else l = mid;
            mid = (l+r)>>1;
        }
        cout<<r<<endl;
    }
    return 0;
}

