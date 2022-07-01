#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

vector <int> f;

struct Nd{
    int x;
    Nd *l = nullptr, *r = nullptr;
};
Nd *root = new Nd;

void push(Nd *cur, int v) {
    if (v > cur->x) {
        if (!cur->r) {
            Nd *nw = new Nd;
            nw->x = v;
            cur->r = nw;
            f[v] = cur->x;
        } else {
            push(cur->r,v);
        }
    } else {
        if (!cur->l) {
            Nd *nw = new Nd;
            nw->x = v;
            cur->l = nw;
            f[v] = cur->x;
        } else {
            push(cur->l,v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    f.assign(n+1,0);
    int r; cin>>r;
    root->x = r;
    for (int i = 0; i < n-1; ++i) {
        cin>>r;
        push(root,r);
    }
    for (int i = 1; i <= n; ++i) {
        cout<<f[i]<<endl;
    }
    return 0;
}
