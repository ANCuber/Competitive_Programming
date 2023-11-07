#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

ll a, b, x, y, N, M;

ll power(ll n, int k, ll P) {
    ll ret = 1, bs = n;
    while(k) {
        if (k&1) ret = ret*bs%P;
        bs = bs*bs%P;
        k >>= 1;
    }
    return ret;
}

ll bf[2005];

void BF() {
    bf[0] = 1;
    for (int i = 1; i <= 2000; ++i) bf[i] = bf[i-1]*b%N;
}

vector<ll> operator* (vector<ll> &A, vector<ll> &B) {
    vector<ll> ret(y+5);
    for (int i = 0; i <= y; ++i) {
        for (int j = 0; j <= y; ++j) {
            if (i+j >= y) {
                ret[y] = (ret[y]+A[i]*B[j]%N*bf[i+j-y]%N)%N;
                continue;
            }
            ret[i+j] = (ret[i+j]+A[i]*B[j]);
            ret[i+j+1] += ret[i+j]/b;
            ret[i+j] %= b;
        }
    }
    for (int i = 0; i < y; ++i) {
        ret[i+1] += ret[i]/b;
        ret[i] %= b;
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>a>>b>>x>>y>>N>>M;
    BF();
    vector<ll> ans(y+5), bs(y+5);
    ans[0] = 1;
    for (int i = 0; a; ++i) {
        if (y == i) {
            bs[i] = a;
            break;
        }
        bs[i] = a%b;
        a /= b;
    }
    while(x) {
        if (x&1) ans = ans*bs;
        bs = bs*bs;
        x >>= 1;
    }
    ll R = 0;
    for (int i = y-1; i >= 0; --i) R = (R+ans[i]*power(b,i,M)%M)%M;
    cout<<ans[y]<<' '<<R<<'\n';
    return 0;
}
