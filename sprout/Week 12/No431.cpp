#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q;
    cin>>n>>m>>q;
    vector <vector <pair<int,int>> > graph(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b, w; cin>>a>>b>>w;
        graph[a].push_back(make_pair(b,w));
    }
    

    for (int i = 0; i < q; ++q) {
        int c, d;
        cin>>c>>d;

    }
}