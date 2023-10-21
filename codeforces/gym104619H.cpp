#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl '\n'

ll N, K;

ll solve(ll n, ll k) {
    //cout<<"Subtree:"<<n<<' '<<k<<endl;
    if (!n) return 0;
    if (k == 1) return 1;
    int p = n+1;
    if ((1ll<<__lg(p)) == p) {
        int l = 0, r = min(__lg(p),k)+1;
        while(r-l > 1) {
            int mid = (l+r)>>1;
            if ((1ll<<(__lg(p)-mid+1))-2 > N-K) l = mid;
            else r = mid;
        }
        //cout<<"Cal:"<<n<<' '<<k<<' '<<((1ll<<min(__lg(p),k))-1-(1ll<<l)+1)<<endl;
        return (1ll<<min(__lg(p),k))-1-((1ll<<l)-1);
    }
    int cur = (1ll<<__lg(n))-1, sub = (1ll<<(__lg(n)-1))-1;
    int flg = 0;
    if (n-1 <= N-K) flg = 1;
    if ((n-cur)*2 >= (1ll<<__lg(n))) {
        return solve(cur,k-1)+solve(n-1-cur,k-1)+flg;
    } else {
        return solve(n-1-sub,k-1)+solve(sub,k-1)+flg;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>N>>K;
    if (K == 1) cout<<1<<endl;
    else cout<<solve(N,K)<<endl;
    return 0;
}

