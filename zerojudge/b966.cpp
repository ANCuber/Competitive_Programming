#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    bitset <10000005> graph;
    graph.reset();
    for (int i = 0; i < n; ++i) {
        int l, r; cin>>l>>r;
        for (int j = l; j < r; ++j)  {
            graph[j] = 1;
        }
    }
    cout<<graph.count()<<'\n';
    return 0;
}
