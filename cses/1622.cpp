#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

set<string> s;
string x;

void dfs(int len, string cur, vector<int> &v) {
    if (len == x.size()) {
        s.insert(cur);
        return;
    }
    for (int i = 0; i < x.size(); ++i) {
        if (!v[i]) {
            v[i] = 1;
            dfs(len+1,cur+x[i],v);
            v[i] = 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>x;
    vector<int> v(x.size()+1,0);
    dfs(0,"\0",v);
    cout<<s.size()<<endl;
    for (auto i : s) {
        cout<<i<<endl;
    }
    return 0;
}
