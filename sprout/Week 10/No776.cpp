#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int n;

struct Matrix{
    
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, l;
    cin>>n>>m>>l;
    vector <vector<int> > graph(n,vector<int> (n,0));
    for (int i; i < m; ++i) {
        int x, y; cin>>x>>y;
        x--, y--;//0 base
        graph[x][y] = 1;
    }

    return 0;
}