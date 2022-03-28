#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> paper;
int n, m, q;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m>>q;
	for (int i = 0; i < n; i++) {
		vector<int> b;
		for (int j = 0, x; j < m; j++){
			cin>>x;
			b.push_back(x);
		}
		paper.push_back(b);
	}
	for (int i = 0, k; i < q; i++) {
		string op; cin>>op; cin>>k;
		if (op == "L") {
			for (int i = 0, l = 2*k-1; i < k; i++, l--) {
				for (int j = 0; j < n; j++) {
					paper[j][l] += paper[j][i];
				}
			}
			for (int j = 0; j < n; j++) {
				paper[j].erase(paper[j].begin(), paper[j].begin()+k);
			}
			m -= k;
		}
		else if (op == "R") {
			for (int i = m-1, l = m-2*k; i > m-1-k; i--, l++) {
				for (int j = 0; j < n; j++) {
					paper[j][l] += paper[j][i];
					paper[j].pop_back();
				}
			}
			m -= k;
		}
		else if (op == "D") {
			for (int i = n-1, l = n-2*k; i > n-1-k; i--, l++) {
				for (int j = 0; j < m; j++) {
					paper[l][j] += paper[i][j];
				}
				paper.pop_back();
			}
			n -= k;
		}
		else if (op == "U") {
			for (int i = 0, l = 2*k-1; i < k; i++, l--) {
				for (int j = 0; j < m; j++) {
					paper[l][j] += paper[i][j];
				}
			}
			paper.erase(paper.begin(), paper.begin()+k);
			n -= k;
		}
		else if (op == "RD") {
			for (int i = m-1, p = k, r = n-1-k; i > m-1-k; i--,p--,r++) {
				for (int j = n-1, s = m-1-k; j > n-1-p; j--,s++) {
					paper[r][s] += paper[j][i];
					paper[j][i] = 0;
				}
			}
		}
		else if (op == "LU") {
			for (int i = 0, p = k; i < k; i++,p--) {
				int layer = k-i;
				for (int j = 0, q = k; j < layer; j++,q--) {
					paper[q][p] += paper[i][j];
					paper[i][j] = 0;
				}
			}
		}
		else if (op == "LD") {
			for (int i = n-1, p = k; i > n-1-k; i--,p--) {
				for (int j = 0, r = n-1-k; j < p; j++,r++) {
					paper[r][p] += paper[i][j];
					paper[i][j] = 0;
				}
			}
		}
		else if (op == "RU") {
			for (int i = 0, p = k, r = m-1-k, u = 1; i < k; i++,p--,r++,u++) {
				for (int j = m-p, s = u; j < m; j++,s++) {
					paper[s][r] += paper[i][j];
					paper[i][j] = 0;
				}
			}
		}
	}
	cout<<n<<' '<<m<<'\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout<<paper[i][j];
			if (j != m-1) cout<<' ';
			else cout<<'\n';
		}
	}
	return 0;
}

