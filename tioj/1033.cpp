#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

struct Ply{
    int p, u, l;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k, n; cin>>k>>n;
    vector<vector<Ply> > p(n+1,vector<Ply>(k<<1|1)); 
    int s;
    for (int i = 1; i <= n; ++i) {
        cin>>s;
        for (int j = 0; j < k<<1|1; ++j) {
            cin>>p[s][j].p;
        }
        for (int j = 0; j < k<<1|1; ++j) {
            cin>>p[s][j].u;
        }
        for (int j = 0; j < k<<1|1; ++j) {
            cin>>p[s][j].l;
        }
    }
    
    return 0;
}
