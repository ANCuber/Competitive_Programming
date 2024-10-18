#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

vector<vector<int> > g(50005), sr(50005);
vector<int> d(50005), vis(50005,0), dis(50005);
vector<bitset<50005> > bs(50005);
queue<int> q;
int cond = 0;

void bfs() {
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto &v : g[u]) {
			
		}
	}
}


int main() {
	int n, m; cin>>n>>m;
	while (m--) {
		int u, v; cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	int mx = -1;
	for (int i = 1; i <= n; ++i) {
		cin>>d[i];
		mx = max(mx,d[i]);
		if (d[i]+1) {
			cond++;
			sr[d[i]].pb(i);
		}
	}
	for (auto &i : sr[mx]) {
		q.push(i);
		bs[i].set(i);
		
	}
	bfs();
	
	return 0;
}
