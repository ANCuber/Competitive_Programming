#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        vector <int> box(n);
        vector <int> tree(m);
        for (int i = 0; i < n; ++i) {
            cin>>box[i];
        }
        for (int i = 0; i < m; ++i) {
            cin>>tree[i];
        }
        sort(tree.begin(), tree.end());

    }
    return 0;
}