#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define ft first
#define sd second

string ans[2] = {"BAD","GOOD"};

bool slv() {
    int n, m; cin>>n>>m;
    vector< pair<string,string> > p(m);
    for (auto& i : p) cin>>i.ft>>i.sd;
    for (int i = 0; i < (1<<n); ++i) {//m = 0, h = 1
        int now = 0;
        for(int j = 0; j < m; ++j) {
            int cur = 0;
            int f, s;
            if (p[j].ft.size() == 2) f = (p[j].ft[1]-'0');
            else if (p[j].ft.size() == 3) f = 10*(p[j].ft[1]-'0')+(p[j].ft[2]-'0');
            
            if (p[j].sd.size() == 2) s = (p[j].sd[1]-'0');
            else if (p[j].sd.size() == 3) s = 10*(p[j].sd[1]-'0')+(p[j].sd[2]-'0');

            f--,s--;

            if (p[j].ft[0] == 'h' && (i>>f)&1) cur=1;
            if (p[j].ft[0] == 'm' && ((i>>f)&1)==0) cur=1;
            
            if (p[j].sd[0] == 'h' && (i>>s)&1) cur=1;
            if (p[j].sd[0] == 'm' && ((i>>s)&1)==0) cur=1;
            now += cur;
        }
        if (now == m) return 1;
    }
    return 0;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        cout<<ans[slv()]<<endl;
    }
    return 0;
}
