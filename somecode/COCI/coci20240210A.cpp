#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int n; cin>>n;
	vector<string> nam(n+2);
	int tb[n+2][6][6];
	for (int i = 0; i < n; ++i) {
		cin>>nam[i];
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				cin>>tb[i][j][k];
			}
		}
	}
	int m; cin>>m;
	for (int i = 0; i < m; ++i) {
		int a; cin>>a;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < 5; ++k) {
				for (int l = 0; l < 5; ++l) {
					if (tb[j][k][l] == a) tb[j][k][l] = 0;
				}
			}
		}
	}
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		vector<int> cnt(10,0), tmp(10,0);
		int z = 1e9, w = 1e9;
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				cnt[j] += tb[i][j][k];
			}
			z = min(z,cnt[j]);
		}
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				tmp[j] += tb[i][k][j];
			}
			w = min(w,tmp[j]);
		}
		int x = 0, y = 0;
		for (int j = 0; j < 5; ++j) {
			x += tb[i][j][j];
			y += tb[i][j][4-j];
		}
		if (x*y*z*w == 0) {
			ans.push_back(i);
		}
	}
	cout<<ans.size()<<'\n';
	for (auto i : ans) cout<<nam[i]<<'\n';
	return 0;
}
