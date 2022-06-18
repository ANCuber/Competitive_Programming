#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<int> a;
vector<int> prexor;
vector<vector<int> > graph;

int main() {
    int n, k; cin>>n>>k;
    a.resize(n+1);
    prexor.resize(n+1,0);
    graph.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        prexor[i] = prexor[i-1]^a[i];
    }
    for (int i = 2; i <= n; ++i) {
        int p; cin>>p;
        graph[p].push_back(i);
    }
}