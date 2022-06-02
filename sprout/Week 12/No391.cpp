#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define ii pair<int, int>

struct Plan {
    int b;
    int c;
    int d;
    int cp;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, m, s, e, f;
        cin>>n>>m>>s>>e>>f;
        vector <vector<Plan> > p(n+1);
        for (int i = 0; i < m; ++i) {
            int a;
            Plan curp;
            cin>>a>>curp.b>>curp.c>>curp.d>>curp.cp;
            p[a].push_back(curp);
        }
        
    }
}