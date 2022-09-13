#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl "\n"
#define int long long

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int k, a;
	int ans = 1;
	vector<int> d(10,6);
	for (int i = 0; i < 6; ++i) {
		cin>>k;
		while(k--) {
			cin>>a;
			d[a]--;
		}
	}
	for (int i = 1; i <= 6; ++i) {
		ans *= d[i];
	}
	cout<<ans<<endl;
	return 0;
}
