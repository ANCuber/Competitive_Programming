#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, k, q = 0;

bool match(int cur, vector<bool> &v, vector<vector<int> > &g, vector<int> &p) {
    for (int i = n+1; i <= (n<<1); ++i) {
        if (g[cur][i] && !v[i]) {
            v[i] = 1;
            if (!p[i] || match(p[i],v,g,p)) {
                p[i] = cur;
                return 1;
            }
        }
    }
    return 0;
}

int hungarian(vector<vector<int> > &g, vector<int> &p) {
    int ans = 0;
    vector<bool> v(n<<1|1,0);
    for (int i = 1; i <= n; ++i) {
        v.assign(n<<1|1,0);
        ans += match(i,v,g,p);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n>>k && (n+k)) {
        vector<vector<int> > g(n<<1|1,vector<int>(n<<1|1,0));
        vector<int> p(n<<1|1,0);
        while(k--) {
            int r, c; cin>>r>>c;
            g[r][c+n] = g[c+n][r] = 1;
        }
        cout<<"Case #"<<++q<<":";
        cout<<hungarian(g,p)<<endl;
    }
    return 0;
}
