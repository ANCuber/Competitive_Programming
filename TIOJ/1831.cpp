#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

int n, m, k;
int a, b;
string x;

void sa() {
    vector<set<int> > v(n+1);
    while(m--) {
        cin>>a>>x>>b;
        if (x == "->") v[a].insert(b);
        else v[b].insert(a);
    }
    for (int i = 1; i <= n; ++i) {
        cout<<i<<" ->";
        if (v[i].empty()) {
            cout<<" 0";
        } else {
            auto it = v[i].begin();
            for (;it != v[i].end(); it++) {
                cout<<' '<<*it;
            }
        }
        cout<<endl;
    }
}

void sb() {
    vector<vector<int> > v(n+1,vector<int>(n+1,0));
    while(m--) {
        cin>>a>>x>>b;
        if (x == "->") v[a][b] = 1;
        else v[b][a] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j!=1) cout<<' ';
            cout<<v[i][j];
        }
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m>>k;
    if (k) {
        sa();
    } else {
        sb();
    }
    return 0;
}
