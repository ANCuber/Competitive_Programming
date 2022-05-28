#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define ii pair<int, int>

struct Edge{
    int w;
    int a, b;
    bool operator<(Edge b){
        return w < b.w;
    }
};

int find_boss(vector <int> &boss, int x) {
    if (boss[x] == x) return x;
    return boss[x] = find_boss(boss,boss[x]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int v, e;
    while(cin>>v>>e) {
        if (!v && !e) break;
        vector <Edge> graph(e);
        for (int i = 0; i < e; ++i) cin>>graph[i].a>>graph[i].b>>graph[i].w;
        sort(graph.begin(),graph.end());
        vector <int> boss(v+1);
        for (int i = 1; i <= v; ++i) boss[i] = i;
        int ans = 0;
        int edge = 0;
        for (int i = 0; i < e; ++i) {
            Edge cur = graph[i];
            if (find_boss(boss,cur.a) == find_boss(boss,cur.b)) {
                continue;
            } else {
                boss[find_boss(boss,cur.a)] = find_boss(boss,cur.b);
                ans += cur.w;
                v--;
            }
        }
        if (v<=1) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}