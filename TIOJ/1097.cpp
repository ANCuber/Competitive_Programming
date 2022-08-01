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

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l, w, a;
    while(cin>>l>>w && l && w) {
        vector<vector<int> > g(l+1,vector<int>(w+1,0));
        for (int i = 1; i <= l; ++i) {
            for (int j = 1; j <= w; ++j) {
                cin>>a;
                g[i][j] = (a != 2);
            }
        }
        
    }
    return 0;
}
