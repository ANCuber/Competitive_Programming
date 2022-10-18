#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

ll n, k;

bool check(int mid, vector<int> &tr) {
    queue<int> q;
    q.push(0);
    ll cnt = 0;
    for (int i = 1; i < n; ++i) {
        while(!q.empty() && tr[i]-tr[q.front()] > mid) q.pop();
        cnt += q.size();
        q.push(i);
    }
    return cnt >= k;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    vector<int> tr(n);
    for (auto& i : tr) cin>>i;
    sort(tr.begin(),tr.end());
    ll l = 0, r = tr[n-1]-tr[0];
    ll mid = (l+r)>>1;
    while(r-l > 1) {
        if (check(mid,tr)) {
            r = mid;
        } else {
            l = mid;
        }
        mid = (l+r)>>1;
    }
    cout<<r<<endl;
    return 0;
}
