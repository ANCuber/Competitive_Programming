#include <bits/stdc++.h>
using namespace std;

struct Node{
    int contain = 1;
    Node *parent = nullptr;
};

void recount (Node *c, int k) {
    c->parent->contain += k;
    if (c->parent->parent != nullptr)
        recount(c->parent,k);
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    for (int l = 1; l <= t; ++l) {
        int n, m; cin>>n>>m;
        vector <Node*> boxes;
        for (int i = 0; i <= n; ++i) {
            boxes.push_back(new Node);
        }
        for (int i = 0; i < m; ++i) {
            int x, y; cin>>x>>y;
            boxes[y]->parent = boxes[x];
            recount(boxes[y], boxes[y]->contain);
        }
        int q; cin>>q;
        for (int i = 0; i < q; ++i) {
            int x; cin>>x;
            cout<<boxes[x]->contain<<'\n';
        }
    }
    return 0;
}