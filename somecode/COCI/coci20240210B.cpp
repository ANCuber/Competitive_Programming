#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int n, t, a, b; cin>>n>>t>>a>>b;
	vector<int> k(n+2,0);
	for (int i = 1; i <= n; ++i) {
		cin>>k[i];
		k[i] += k[i-1];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {//read to the ith book
		if ((i)*b > t) break;
		int cur = t-(i)*b;
		int r = cur/(a-b);
		ans = max(ans,k[i]-k[max(i-r,0ll)]);
	}
	cout<<ans<<endl;
	return 0;
}
