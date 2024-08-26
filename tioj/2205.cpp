#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mid ((l+r)>>1)

const ll M = 1e9+289;
const ll A = 31;
ll invA;

struct SEG{
	vector<ll> a;
	void init(int _n) {
		a.assign(_n<<2,0);
	}
	void mdf(int l, int r, int p, int t, ll x) {
		if (l == r) {
			a[p] = x%M;
			return;
		}
		if (t <= mid) mdf(l,mid,p<<1,t,x);
		else mdf(mid+1,r,p<<1|1,t,x);
		a[p] = (a[p<<1]+a[p<<1|1])%M;
	}
	ll query(int l, int r, int p, int ql, int qr) {
		if (ql <= l && r <= qr) return a[p]%M;
		if (qr <= mid) return query(l,mid,p<<1,ql,qr)%M;
		else if (ql > mid) return query(mid+1,r,p<<1|1,ql,qr)%M;
		else return (query(l,mid,p<<1,ql,qr)+query(mid+1,r,p<<1|1,ql,qr))%M;
	}
}frt, bck;

ll power(ll a, int x) {
	ll ret = 1, bs = a;
	while(x) {
		if (x&1) ret = ret*bs%M;
		bs = bs*bs%M;
		x >>= 1;
	}
	return ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	int n, q; cin>>n>>q;
	frt.init(n), bck.init(n);
	string s; cin>>s;
	for (int i = 0; i < n; ++i) {
		frt.mdf(1,n,1,i+1,(s[i]-'a')*power(A,i)%M);
		bck.mdf(1,n,1,i+1,(s[i]-'a')*power(A,n-i-1)%M);
	}
	invA = power(A,M-2);
	while(q--) {
		int t, l, r;
		cin>>t>>l>>r;
		l--, r--;
		if (t == 1) {
			if ((r-l+1)%3) {
				cout<<"0\n";
				continue;
			}
			int sec = (r-l+1)/3;
			//cout<<l<<' '<<l+sec<<' '<<l+sec+sec<<endl;
			ll x = frt.query(1,n,1,l+1,l+sec-1+1)*power(invA,l)%M;
			ll z = frt.query(1,n,1,l+2*sec+1,r+1)*power(invA,l+2*sec)%M;
			ll y = bck.query(1,n,1,l+sec+1,l+2*sec-1+1)*power(invA,n-1-(l+2*sec-1))%M;
			if (x == z && z == y) cout<<"1\n";
			else cout<<"0\n";
		} else {
			frt.mdf(1,n,1,l+1,(s[r]-'a')*power(A,l)%M), frt.mdf(1,n,1,r+1,(s[l]-'a')*power(A,r)%M);
			bck.mdf(1,n,1,l+1,(s[r]-'a')*power(A,n-1-l)%M), bck.mdf(1,n,1,r+1,(s[l]-'a')*power(A,n-1-r)%M);
			swap(s[l],s[r]);
		}
	}
    return 0;
}
