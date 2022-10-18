#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n;

void dfs(int len, vector<int> &v, int j) {
    if (!len) {
        for (int i = 0; i < v.size(); ++i) {
            if (i) cout<<", ";
            cout<<v[i];
        }
        cout<<endl;
        return;
    }
    
    for (int i = j; i <= len/2; ++i) {
        v.pb(i);
        dfs(len-i,v,max(i,j));
        v.pop_back();
    }
    for (int i = 0; i < v.size(); ++i) {
        if (i) cout<<", ";
        cout<<v[i];
    }
    cout<<", "<<len<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    for (int i = 1; i <= t; ++i) {
        cout<<"Plank "<<i<<":\n";
        cin>>n;
        vector<int> v;
        for (int j = 1; j <= n/2; ++j) {
            v.pb(j);
            dfs(n-j,v,j);
            v.pop_back();
        }
    }
    return 0;
}
