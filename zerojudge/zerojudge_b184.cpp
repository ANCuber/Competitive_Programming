#include <bits/stdc++.h>
using namespace std;

int v[10005], c[10005];
int cost[10005][10005];

int container(int a, int b) {
    if (b < 0) return -1e9;
    if (a == 0) return 0;

    if (cost[a][b] != 0) return cost[a][b];
    return cost[a][b] = max(
        container(a-1,b),
        container(a-1,b-v[b]) + c[b]
    );
}

int main() {
    int n;
    while(cin>>n) {
        for (int i = 1; i <= n; i++)
            cin>>v[i]>>c[i];
        cout<<container(n,100)<<'\n';
    }
    return 0;
}