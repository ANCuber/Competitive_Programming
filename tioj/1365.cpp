#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct BIT{
    vector<int> a;
    int sz;
    void init(int _n) {
        a.assign(_n+5,0);
        sz = _n;
    }
    void add(int p, int v) {
        while(p <= sz) {
            a[p] += v;
            p += p&-p;
        }
    }
    int sum(int p) {
        int ans = 0;
        while(p) {
            ans += a[p];
            p -= p&-p;
        }
        return ans;
    }
} bit;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    bit.init(1e6+1);
    vector<pii> car(1000005);
    while(cin>>n) {
        for (int i = 0; i < n; ++i) {
            cin>>car[i].first>>car[i].second;
            car[i].first++, car[i].second++;
        }
        int ans = 0;
        sort(car.begin(),car.begin()+n);
        for (int i = 0; i < n; ++i) {
            ans += (bit.sum(1e6+1)-bit.sum(car[i].second));
            bit.add(car[i].second,1);
        }
        cout<<ans<<endl;
        for (int i = 0; i < n; ++i) bit.add(car[i].second,-1);
    }
    return 0;
}
