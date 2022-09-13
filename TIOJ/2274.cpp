#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl "\n"
#define int long long

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin>>n>>m;
	vector<vector<int> > g(n+2,vector<int>(m+2,0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin>>g[i][j];
		}
	}
	int x = 0, y = 0, mxx = -1e18, mxy = -1e18;
	for (int i = 1; i <= n; ++i) {
		int ans = g[i][1], sum = g[i][1];
		for (int j = 2; j <= m; ++j) {
			if (sum<0) {
				sum = g[i][j];
			} else {
				sum += g[i][j];
			}
			ans = max(ans,sum);
		}
		if (mxx < ans) {
			x = i;
			mxx = ans;
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		int ans = g[1][i], sum = g[1][i];
		for (int j = 2; j <= n; ++j) {
			if (sum<0) {
				sum = g[j][i];
			} else {
				sum += g[j][i];
			}
			ans = max(ans,sum);
		}
		if (mxy < ans) {
			y = i;
			mxy = ans;
		}
	}
	//cout<<x<<' '<<y<<endl;
	int st=1, ed=1, sum = -1e18;
	if (mxx > mxy) {
		vector <int> s(m+5,0);
		for (int i = 1; i <= m; ++i) s[i] = s[i-1]+g[x][i];
		for (int j = 1; j <= m; ++j) {
			for (int k = j; k <= m; ++k) {
				if (sum < s[k]-s[j-1]) {
					sum = s[k]-s[j-1];
					st = j, ed = k;
				}
			}
		}
		cout<<sum<<endl;
		for (int i = 1; i < st; ++i) cout<<"L";
		for (int i = m; i > ed; --i) cout<<"R";
		for (int i = 1; i <= n; ++i) cout<<"U";
	} else {
		vector <int> s(n+5,0);
		for (int i = 1; i <= n; ++i) s[i] = s[i-1]+g[i][y];
		for (int j = 1; j <= n; ++j) {
			for (int k = j; k <= n; ++k) {
				if (sum < s[k]-s[j-1]) {
					sum = s[k]-s[j-1];
					st = j, ed = k;
				}
			}
		}
		cout<<sum<<endl;
		for (int i = 1; i < st; ++i) cout<<"U";
		for (int i = n; i > ed; --i) cout<<"D";
		for (int i = 1; i <= m; ++i) cout<<"R";
	}
	cout<<endl;
	return 0;
}
