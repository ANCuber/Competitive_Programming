#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    vector<vector<int> > g(n+1,vector<int>(n+1,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++i) {
            cin>>g[i][j];
        }
    }
    int q; cin>>q;
    int sx, sy, tx, ty;
    while(q--) {
        cin>>sx>>sy>>tx>>ty;

    }
}