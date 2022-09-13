#include <bits/stdc++.h>
using namespace std;

int n, m;

bool solve (priority_queue <int> box, vector <int> tree, int k) {
    for (int i = k-1; i >= 0; --i) {
        if (tree[i] > box.top()) return 0;
        int x = box.top()-tree[i];
        box.pop();
        box.push(x);
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        priority_queue <int> box;
        vector <int> tree(m);
        for (int i = 0; i < n; ++i) {
            int x; cin>>x;
            box.push(x);
        }
        for (int i = 0; i < m; ++i) {
            cin>>tree[i];
        }
        sort(tree.begin(), tree.end());
        if (box.top() < tree[0]) {
            cout<<0<<'\n';
            continue;
        }
        /* for (int i = 1; i <= m; ++i) {
            cout<<i<<' '<<solve(box,tree,i)<<'\n';
        } */
        if (solve(box,tree,m)) {
            cout<<m<<'\n';
            continue;
        }
        int high = m;
        int low = 1;
        int guess = (high+low)/2;
        while(high > low) {
            if (solve(box,tree,guess)) {
                low = guess+1;
            } else {
                high = guess;
            }
            guess = (high+low)/2;
        }
        cout<<guess-1<<'\n';
    }
    return 0;
}