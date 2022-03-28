#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n, m, c; cin>>n>>m>>c;
	long long sche[m] = {0};
	for (int i = 0; i < n-1; i++) {
		int l, r, a; cin>>l>>r>>a;
		for (int i = l-1; i < r; i++) {
			sche[i] += a;
		}
	}
	int ci[m];
	long long maxinp = 0;
	for (int i = 0; i < m; i++) {
		cin>>ci[i];
		if (maxinp < sche[i]) maxinp = sche[i];
	}
	maxinp -= c;
	int mincost = 1000005;
	for (int i = 0; i < m; i++) {
		if (sche[i] >= maxinp) {
			if (ci[i] <= mincost) {
				mincost = ci[i];
			}
		} 
	}
	cout<<mincost<<'\n';
	return 0;
}
