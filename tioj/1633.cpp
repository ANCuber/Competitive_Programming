#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Treap{
    int pri, sz, tg, ky;
    Treap *lc, *rc;
    Treap(int val) {
        ky = val;
        pri = rand();
        sz = 1;
        lc = rc = nullptr;
    }
};

inline int size(Treap *p) {
    return p?p->sz:0;
}

inline void updsz(Treap *p) {
    if(p) p->sz = size(p->lc)+size(p->rc)+1;
}

void push(Treap *p) {
    if (!p || !p->tg) return;
    swap(p->lc,p->rc);
    p->tg = 0;
    if(p->lc) p->lc->tg ^= 1;
    if(p->rc) p->rc->tg ^= 1;
}

Treap *merge(Treap *a, Treap *b) {
    if (!a || !b) return a?a:b;
    if (a->pri < b->pri) {
        push(a);
        a->rc = merge(a->rc,b);
        updsz(a);
        return a;
    } else {
        push(b);
        b->lc = merge(a,b->lc);
        updsz(b);
        return b;
    }
}

void split(Treap *p, Treap *&a, Treap *&b, int k) {
    if (!p) {
        a = b = nullptr;
        return;
    }
    push(p);
    if (size(p->lc)+1 <= k) {
        a = p;
        split(p->rc,a->rc,b,k-size(p->lc)-1);
        updsz(a);
    } else {
        b = p;
        split(p->lc,a,b->lc,k);
        updsz(b);
    }
}

int flag = 0;

void dfs(Treap *p) {
    if (!p) return;
    push(p);
    dfs(p->lc);
    if (flag) cout<<' ';
    flag = 1;
    cout<<(p->ky);
    dfs(p->rc);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    srand(time(NULL));
    Treap *root = nullptr;
    for (int i = 1; i <= n; ++i) root = merge(root,new Treap(i));
    string cmd;
    int a, b, c, d;
    while(m--) {
        cin>>cmd;
        if (cmd[0] == 'R') {
            cin>>a>>b;
            Treap *x, *y, *z;
            split(root,x,y,a-1);
            split(y,y,z,b-a+1);
            y->tg ^= 1;
            root = merge(merge(x,y),z);
        } else {
            cin>>a>>b>>c>>d;
            Treap *x, *y, *z, *w, *v;
            split(root,x,y,a-1);
            split(y,y,z,b-a+1);
            split(z,z,w,c-b-1);
            split(w,w,v,d-c+1);
            root = merge(merge(x,w),merge(merge(z,y),v));
        }
    }
    dfs(root);
    cout<<endl;
    return 0;
}
