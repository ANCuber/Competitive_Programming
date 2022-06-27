#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define ii pair<int, int>

struct Edge {
    int b;
    int c;
    int d;
    int cp;
};

struct Node{
    vector <Edge> link;
    unsigned ll price;
    bool inque;
};
Node node[101];

unsigned ll SPFA(int s, int d, int f) {
    queue<int> q;
    q.push(s);
    node[s].price = 0LL;
    node[s].inque = true;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        node[cur].inque = false;
        for (auto i : node[cur].link) {
            unsigned ll p = node[cur].price+min(f,i.d)*(unsigned ll)i.c+max(f-i.d,0)*(unsigned ll)i.cp;
            if (p < node[i.b].price) {
                node[i.b].price = p;
                if (!node[i.b].inque) {
                    q.push(i.b);
                    node[i.b].inque = true;
                }
            }
        }
    }

    return node[d].price;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, m, s, e, f;
        cin>>n>>m>>s>>e>>f;
        for (int i = 0; i <= n; ++i) {
            node[i].link.clear();
            node[i].price = 2e18;
            node[i].inque = false;
        }

        for (int i = 0; i < m; ++i) {
            int a;
            Edge curp;
            cin>>a>>curp.b>>curp.c>>curp.d>>curp.cp;
            node[a].link.push_back(curp);
        }
        
        cout<<SPFA(s,e,f)<<endl;
    }
    return 0;
}