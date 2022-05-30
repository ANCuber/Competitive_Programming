#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define ii pair<int, int>

int main() {
    int n, m; cin>>n>>m;
    int A, B; cin>>A>>B;
    vector <vector <int> > graph(n+1);
    for (int i = 0; i < m; ++i) {
        int x, y; cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector <int> dis(n+1,1e9);
    dis[A] = 0;
    int p = A;
    for (int i = 0;i < n; ++i) {
       
    }
    while (true) {

    }

}