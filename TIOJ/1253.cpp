#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    while(cin>>n>>k && n && k) {
        vector<vector<int> > g(n+1,vector<int>(n+1,0));
        vector<int> x(n+1,0);
        vector<int> y(n+1,0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int a, b; cin>>a>>b;
                g[a][b] = 1;
                x[a]++;
                y[b]++;
            }
        }
        
    }
    return 0;
}