#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int u, v;
    while(cin>>n && n) {
        vector<vector<vector<int> > > tr(2,vector<vector<int> >(n+1,vector<int>(n+1)));
        for (int i = 0; i < 2*n-2; ++i) {
            cout<<u<<v;
            tr[i/(n-1)][u][v] = tr[i/(n-1)][v][u] = 1;
        }
        
    }
    return 0;
}
