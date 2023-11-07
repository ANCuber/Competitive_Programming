#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int P = 1e9+7;
const int B = 27;

int m[5005], inv[5005];

int power(int a, int x) {
    int ret = 1, bs = a;
    while(x) {
        if (x&1) ret = ret*bs%P;
        bs = bs*bs%P;
        x >>= 1;
    }
    return ret;
}

vector<int> Hash(string &s) {
    vector<int> h(s.size(),0);
    for (int i = 0; i < s.size(); ++i) {
        h[i] = (h[i-1]+m[i]*(s[i]-'a')%P)%P;
    }
    return h;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    m[0] = 1, inv[0] = 5e8+4;
    for (int i = 1; i <= 5000; ++i) {
        m[i] = m[i-1]*B%P;
        inv[i] = power(m[i],P-2);
    }
    int n;
    while(cin>>n && n) {
        vector<string> a(n);
        vector<vector<int> > H(n);
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            H[i] = Hash(a[i]);
        }
        int l = 0, r = 5000;
        while(r-l > 1) {
            int mid = (l+r)/2;
            set<int> s;
            for (int i = 0; i < n; ++i) {
                if ((int)(a[i].size())-mid <= 0) continue;
                int cur;
                if (mid) cur = (H[i][a[i].size()-1]-H[i][mid-1]+P)%P*inv[mid]%P;
                else cur = H[i][a[i].size()-1];
                //cout<<cur<<endl;
                s.insert(cur);
            }
            //cout<<mid<<' '<<s.size()<<endl;
            if (s.size() == n) l = mid;
            else r = mid;
        }
        cout<<l<<endl;
    }
    return 0;
}

