#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int k = 33;
string pre, in;
vector<int> pos(100);

void dfs(int l, int r, int d) {
    if (l < r) {
        int mid = pos[pre[d]-k];
        if (l < mid) dfs(l,mid-1,d+1);
        if (r > mid) dfs(mid+1,r,d+mid-l+1);
    }
    cout<<pre[d];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>pre>>in) {
        pos.assign(100,0);
        for (int i = 0; i < in.size(); ++i) pos[in[i]-k] = i; 
        dfs(0,pre.size()-1,0);
        cout<<endl;
    }
    return 0;
}
