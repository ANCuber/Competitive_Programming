#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q;
    cin>>n>>m>>q;
    vector <vector <pair<int,int>> > graph(n+1);
    vector <vector <pair<int,int>> > back(n+1);
    p_q <pair<ll,int>,vector<pair<ll,int> >, greater<pair<ll,int> > > pq1, pq2;
    for (int i = 0; i < m; ++i) {
        int a, b, w; cin>>a>>b>>w;
        graph[a].emplace_back(b,w);
        back[b].emplace_back(a,w);
    }
    vector <ll> go(n+1,1e18);
    vector <bool> vis1(n+1,0);
    go[1] = 0;
    vector <ll> re(n+1,1e18);
    vector <bool> vis2(n+1,0);
    re[n] = 0;
    
    pq1.push({0,1});
    pq2.push({0,n});

    while (!pq1.empty()) {
        int cur = pq1.top().second;
        pq1.pop();
        if (vis1[cur]) continue;
        vis1[cur] = true;

        for (auto i : graph[cur]) {
            if (go[i.first] > go[cur]+i.second) {
                go[i.first] = go[cur]+i.second;
                pq1.push({go[i.first],i.first});
            }
        }
    }
    while (!pq2.empty()) {
        int cur = pq2.top().second;
        pq2.pop();
        if (vis2[cur]) continue;
        vis2[cur] = true;

        for (auto i : back[cur]) {
            if (re[i.first] > re[cur]+i.second) {
                re[i.first] = re[cur]+i.second;
                pq2.push({re[i.first],i.first});
            }
        }
    }
    /* for (auto i : go) cout<<i<<' ';
    cout<<endl;
    for (auto i : re) cout<<i<<' ';
    cout<<endl; */
    while(q--) {
        int c, d;
        cin>>c>>d;
        cout<<min(go[c]+re[d]+1,go[n])<<endl;
    }
    return 0;
}

/* 6 5 3
1 2 1
2 3 1 
3 4 1
4 5 1
5 6 1
2 5
1 6
3 2 */

/* 8 9 5
1 2 1
1 3 1
2 4 1
2 6 1
3 5 1
4 7 1
5 6 1
6 8 1
7 8 1
6 1 
1 6
1 2
5 8
2 8 */

