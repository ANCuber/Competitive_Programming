#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl "\n"
#define int long long

int n, q;

struct Node {
	int lc = 0, rc = 0;
};

int ff(int x, vector<int> &fa) {
	if (x == fa[x]) return x;
	return fa[x] = ff(fa[x],fa);
}

void prdfs(int cur, vector<Node> &g, int& cnt, vector<int> &pr) {
	pr[++cnt] = cur;
	if (g[cur].lc) prdfs(g[cur].lc,g,cnt,pr);
	if (g[cur].rc) prdfs(g[cur].rc,g,cnt,pr);
}

void indfs(int cur, vector<Node> &g, int& cnt, vector<int> &in) {
	if (g[cur].lc) indfs(g[cur].lc,g,cnt,in);
	in[++cnt] = cur;
	if (g[cur].rc) indfs(g[cur].rc,g,cnt,in);
}

void sbdfs(int cur, vector<Node> &g, int& cnt, vector<int> &sb) {
	if (g[cur].lc) sbdfs(g[cur].lc,g,cnt,sb);
	if (g[cur].rc) sbdfs(g[cur].rc,g,cnt,sb);
	sb[++cnt] = cur;
}

void add(int& sz, int a, int b, vector<int> &fa) {
	if (ff(a,fa) != ff(b,fa)) {
		sz--;
		fa[ff(a,fa)] = ff(b,fa);
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>q;

	vector<Node> g(n+1);
	vector<int> fa(n+1);
	vector<int> pr(n+1), in(n+1), sb(n+1);
	
	for (int i= 0; i <= n; ++i) fa[i] = i;
	
	for (int i = 2; i <= n; ++i) {
		int p, t; cin>>p>>t;
		if (t) g[p].rc = i;
		else g[p].lc = i;
	}
	int cnt = 0;
	prdfs(1,g,cnt,pr);
	cnt = 0;
	indfs(1,g,cnt,in);
	cnt = 0;
	sbdfs(1,g,cnt,sb);
	
	int sz = n;
	for (int i= 1; i <= (n+1)/2; ++i) {
		add(sz,pr[i],pr[n-i+1],fa);
		add(sz,in[i],in[n-i+1],fa);
		add(sz,sb[i],sb[n-i+1],fa);
	}
	cout<<sz<<endl;
	
	while (q--) {
		int u, v; cin>>u>>v;
		add(sz,u,v,fa);
		cout<<sz<<endl;
	}
	return 0;
}
