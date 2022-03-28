#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	long long n, m; cin>>n>>m;
	int q, days = 0; cin>>q;
	long long sx, sy, ex, ey, x, y;
	for (int i = 0; i < q; i++) {
		cin>>sx>>sy>>ex>>ey>>x>>y;
		if ((sx == x && ey == y) || (sy == y && ex == x)) {
			days++;
			continue;
		}
		if ((sx == x && ex == x) || (sy == y && ey == y)) {
			days++;
			continue;
		}
		if (sx == ex && sy == ey) {
			days++;
			continue;
		}
	}
	cout<<days<<'\n';
	return 0;
}
