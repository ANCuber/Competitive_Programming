#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int maxn = 1e5;

struct SEG{
    struct Node{
        int cnt = 0;
        Node *lc = nullptr, *rc = nullptr;
    };
    vector<Node*> rt;
    void initset(int l, int r, Node *p) {
        if (l == r) return;
        p->lc = new Node, p->rc = new Node;
        int mid = (l+r)>>1;
        initset(l,mid,p->lc), initset(mid+1,r,p->rc);
    }
    void init() {
        Node *root = new Node;
        rt.pb(root);
        initset(1,maxn,root);
    }
    void upd(int l, int r, Node *cur, Node *pre, int v) {
        cur->cnt = pre->cnt+1;
        if (l == r) {
            //cur->cnt++;
            return;
        }
        int mid = (l+r)>>1;
        if (v <= mid) {
            cur->rc = pre->rc;
            cur->lc = new Node;
            upd(l,mid,cur->lc,pre->lc,v);
        } else {
            cur->lc = pre->lc;
            cur->rc = new Node;
            upd(mid+1,r,cur->rc,pre->rc,v);
        }
        //cur->cnt = cur->lc->cnt+cur->rc->cnt;
    }
    void addnew(int v) {
        Node *root = new Node;
        upd(1,maxn,root,rt.back(),v);
        rt.pb(root);
    }
    int query(int l, int r, int k, Node *a, Node *b) {
        if (l == r) return l;
        int mid = (l+r)>>1;
        if (b->rc->cnt - a->rc->cnt >= k) {
            return query(mid+1,r,k,a->rc,b->rc);
        } else {
            return query(l,mid,k-(b->rc->cnt-a->rc->cnt),a->lc,b->lc);
        }
    }
} seg;


signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    int a, b, k;
    vector<int> arr(n);
    set<int> s;
    map<int,int> mp, rev;
    for (auto& i : arr) {
        cin>>i;
        s.insert(i);
    }
    int c = 0;
    for (auto i : s) {
        mp[i] = ++c;
        rev[c] = i;
    }
    seg.init();
    for (auto i : arr) {
        seg.addnew(mp[i]);
    }
    while(m--) {
        cin>>a>>b>>k;
        cout<<rev[seg.query(1,maxn,k,seg.rt[a-1],seg.rt[b])]<<endl;
    }
    return 0;
}
