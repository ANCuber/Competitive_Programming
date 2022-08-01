#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

struct Pt{int x, y, z;};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x, y, z;
    cin>>x>>y>>z;
    vector<vector<vector<int> > > g(x+2,vector<vector<int> >(y+2,vector<int>(z+2,0)));
    for (int i = 1; i <= z; ++i) {
        for (int j = 1; j <= y; ++j) {
            for (int k = 1; k <= x; ++k) {
                cin>>[k][j][i];
            }
        }
    }
    queue <int> q;
    q.push({1,1,1});
    
    
    return 0;
}
