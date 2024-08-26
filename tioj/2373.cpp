#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

struct BIT{
    vector<int> a;
    int sz;
    void init(int _n) {
	sz = _n;
	a.assign(_n+5,0);
    }
    void mdf(int p, int x) {
	while(p <= sz) {
	    a[p] += x;
	    p += p&-p;
	}
    }
    int sum(int p) {
	int ret = 0;
	while(p) {
	    ret += a[p];
	    p -= p&-p;
	}
	return ret;
    }
} bit;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin>>n>>k;
    bit.init(n);
    vector<int> a(n+2), s(n);
    for (int i = 1; i <= n; ++i) {
	cin>>a[i];
	s[i-1] = a[i];
    }
    sort(s.begin(),s.end(),greater<int>());
    int l = -1, r = n;
    while(r-l > 1) {
	int mid = (l+r)>>1;
	if (s[mid] <= s[k-1]) r = mid;
	else l = mid;
    }
    int cnt = k-r, tmp = 0;
    //cout<<"Cnt:"<<cnt<<endl;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
	if (a[i] > s[k-1]) {
	    ans += bit.sum(i);
	} else if (tmp < cnt && a[i] == s[k-1]) {
	    //cout<<"=:"<<i<<endl;
	    tmp++;
	    ans += bit.sum(i);
	} else {
	    bit.mdf(i,1);
	}
    }
    //for (int i = 1; i <= n; ++i) cout<<bit.sum(i)-bit.sum(i-1)<<' '; cout<<endl;
    cout<<ans<<'\n';
    return 0;
}
