#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct Node{
    int key, pri, sz;
    Node *lc, *rc;
    Node(int k) {
        key = k;
        pri = rand();
        sz = 1;
        lc = rc = nullptr;
    }
};

inline int size(Node *p) {
    return p?p->sz:0;
}

inline void pull(Node *p) {
    if (p) p->sz = size(p->lc)+size(p->rc)+1;
}

Node *merge(Node *a, Node *b) {
    if (!a || !b) return a?a:b;
    if (a->pri < b->pri) {
        a->rc = merge(a->rc,b);
        pull(a);
        return a;
    } else {
        b->lc = merge(a,b->lc);
        pull(b);
        return b;
    }
}


void bysz(Node *p, Node *&a, Node *&b, int k) {
    if (!p) a = b = nullptr;
    else if (size(p->lc) >= k) {
        b = p;
        bysz(p->lc,a,b->lc,k);
        pull(b);
    } else {
        a = p;
        bysz(p->rc,a->rc,b,k-size(p->lc)-1);
        pull(a);
    }
}

void bykey(Node *p, Node *&a, Node *&b, int k) {
    if (!p) a = b = nullptr;
    else if (p->key <= k) {
        a = p;
        bykey(p->rc,a->rc,b,k);
        pull(a);
    } else {
        b = p;
        bykey(p->lc,a,b->lc,k);
        pull(b);
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    srand(time(NULL));
    Node *root = nullptr;
    vector<int> p(n+1);
    for (int i = 1; i <= n; ++i) cin>>p[i];
    for (int i = 1; i <= n; ++i) {
        Node *x, *y;
        bykey(root,x,y,p[i]);
        root = merge(merge(x,new Node(p[i])),y); 
    }
    char cmd;
    int a, b, ans;
    while(q--) { 
        cin>>cmd>>a>>b;
        Node *x, *y, *z, *d, *u, *v;
        if (cmd == '!') {
            bykey(root,x,y,p[a]-1);
            bykey(y,y,z,p[a]);
            bysz(y,y,d,1);
            root = merge(merge(x,d),z);
            bykey(root,u,v,b);
            root = merge(merge(u,new Node(b)),v);
            p[a] = b;
        } else {
            bykey(root,x,y,a-1);
            ans = -size(x);
            root = merge(x,y);
            bykey(root,u,v,b);
            ans += size(u);
            root = merge(u,v);
            cout<<ans<<endl;
        }
    }
    return 0;
}
