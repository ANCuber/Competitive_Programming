#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

inline int cal (int x1, int y1, int x2, int y2) {
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<vector<int> > s(2);
    for (int i = 0; i < 2; ++i) {
        int a, b, c, d, e, f;
        cin>>a>>b>>c>>d>>e>>f;
        
        s[i].pb(cal(a,b,c,d));
        s[i].pb(cal(c,d,e,f));
        s[i].pb(cal(e,f,a,b));
    }
    sort(s[0].begin(),s[0].end());
    sort(s[1].begin(),s[1].end());
    
    int q; cin>>q;
    while(q--) {
        int a, b, c, d, e, f;
        cin>>a>>b>>c>>d>>e>>f;
        vector<int> cur;
        cur.pb(cal(a,b,c,d));
        cur.pb(cal(c,d,e,f));
        cur.pb(cal(e,f,a,b));
        sort(cur.begin(),cur.end());
        if (cur == s[0]) cout<<"Nijika"<<endl;
        else if (cur == s[1]) cout<<"Doritos"<<endl;
        else cout<<"None"<<endl;
    }

    
    return 0;
}
