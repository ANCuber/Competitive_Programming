#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int counter[500005];
const int mod = 1e9+7;

int hs(int n){
    n = ((n >> 16) ^ n) * 0x45d9f3b;
    n = ((n >> 16) ^ n) * 0x45d9f3b;
    n = (n >> 16) ^ n;// from stack overflow(a uniform hash function for int32);
    return n;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, q;
    cin>>n>>k>>q;
    vector <int> sum(n+1,0);
    for (int i = 1; i <= n; ++i) {
        int a; cin>>a;
        counter[a]++;
        if (counter[a]%k) {
            sum[i] = (sum[i-1]+hs(a)%mod)%mod;
        } else {
            sum[i] = (sum[i-1]+(1LL*(1-k)*hs(a))%mod)%mod;
        }
    }
    vector <int> ans;
    while(q--) {
        int l, r; cin>>l>>r;
        cout<<((sum[r]-sum[l-1])%mod==0);
    }
    cout<<endl;
    return 0;
}

/* 10 2 10
1 2 3 2 4 4 3 1 3 1
1 8
1 10
5 6
1 4
5 10
2 7
1 7
8 9
7 9
3 7
 */