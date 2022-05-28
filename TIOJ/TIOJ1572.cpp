#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define ii pair<int, int>

int main() {
    int v, e; cin>>v>>e;
    int A, B; cin>>A>>B;
    vector <vector <int> > graph(v+1);
    for (int i = 0; i < e; ++i) {
        int x, y; cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector <int> dis(v+1,1e9);
    vector <bool> visited(v+1,0);
    dis[A] = 0;
    int p = A;
    while (true) {

    }

}