#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int k, mxc = 30;

struct Query{
    int l, r, id;
    bool operator<(Query b) {
        if (r/k == b.r/k) return l < b.l;
        return r/k < b.r/k;
    }
};

struct TRIE{
    struct Node{
        int cnt = 0;
        Node *lc = nullptr, *rc = nullptr;
        // 0, 1
    };
    vector<Node*> root;
    void init() {
        root.pb(new Node);
    }
    void mdf(int v, int b, Node *pre, Node *cur) {
        if ((v>>b)&1) {
            cur->lc = pre->lc;
            cur->rc = new Node;
            cur->rc->cnt = pre->rc->cnt+1;
            if (b > 0) mdf(v,b-1,pre->rc,cur->rc);
        } else {
            cur->lc = new Node;
            cur->rc = pre->rc;
            cur->lc->cnt = pre->lc->cnt+1;
            if (b > 0) mdf(v,b-1,pre->lc,cur->lc);
        }
    }
    void addtrie(int v) {
        Node *cur = new Node;
        mdf(v,mxn,root.back(),cur);
        root.pb(cur);
    }
    int query(int l, int r, int v) {
        l--;
        Node *ltr = root[l], *rtr = root[r];
        int mx = v;
        for (int i = mxc; i >= 0; --i) {
            int lcv, rcv;
            if (ltr->lc) lcv = ltr->lc->cnt;
            else {
                ltr->lc = new Node;
                lcv = 0;
            }
            if (ltr->rc) rcv = ltr->rc->cnt;
            else {
                ltr->rc = new Node;
                rcv = 0;
            }
            if ((v>>i)&1) {
                if (rtr->lc->cnt - lcv) {
                    ltr = ltr->lc;
                    rtr = rtr->lc;
                } else {
                    ltr = ltr->rc;
                    rtr = rtr->rc;
                    mx ^= (1<<i);
                }
            } else {
                if (rtr->rc->cnt - rcv) {
                    ltr = ltr->rc;
                    rtr = rtr->rc;
                    mx ^= (1<<i);
                } else {
                    ltr = ltr->lc;
                    rtr = rtr->lc;
                }
            }
        }
        return mx;
    }
} trie;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, Q; cin>>N>>Q;
    k = N/sqrt(Q);
    trie.init();
    vector<int> a(N+2,0);
    for (int i = 1; i <= N; ++i) {
        cin>>a[i];
        a[i] |= a[i-1];
    }
    for (int i = 1; i <= N; ++i) trie.addtrie(a[i]);
    vector<Query> q(Q+1);
    for (int i = 1; i <= Q; ++i) {
        cin>>q[i].l>>q[i].r;
        q[i].id = i;
    }
    sort(q.begin()+1,q.end());
    q[0].id = 0;
    for (auto [l,r,id] : q) {
        if (!id) continue;
        
    }
    
    return 0;
}
