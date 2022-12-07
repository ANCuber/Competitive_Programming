#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int maxn = 2000005;

int n, m;
ll bs, num;
string x;
string ans[2] = {"FALSE","TRUE"};

struct TRIE{
    vector<vector<int> > t;
    vector<int> sp;
    int cnt = 0;
    void init() {
        t.assign(maxn,vector<int>(2,0));
        sp.assign(maxn,0);
    }
    void upd(int p, ll v, ll d, int n) {
        int c = (v>>d)&1;
        if (!t[p][c]) t[p][c] = ++cnt;
        if (d > n) upd(t[p][c],v,d-1,n);
        else sp[t[p][c]] = 1;
    }
    int query(int p, ll v, ll d) {
        if (sp[p]) return 1;
        int c = (v>>d)&1;
        //cout<<c;
        if (!t[p][c]) return sp[p];
        return query(t[p][c],v,d-1);
    }
} trie;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>m>>n;
    trie.init();
    while(m--) {
        cin>>x;
        bs = 0, num = 0;
        for (int i = 0; i < x.size(); ++i) {
            if (x[i] == '/') {
                num = (num<<8)+bs;
                bs = 0;
                continue;
            }
            if (x[i] == '.') {
                num = (num<<8)+bs;
                bs = 0;
            }
            else bs = bs*10+(x[i]-'0');
        }
        trie.upd(0,num,1ll*32,32-bs);
    }
    while(n--) {
        cin>>x;
        bs = 0, num = 0;
        for (int i = 0; i < x.size(); ++i) {
            if (x[i] == '.') {
                num = (num<<8)+bs;
                bs = 0;
            }
            else bs = bs*10+(x[i]-'0');
        }
        num = (num<<8)+bs;
        cout<<ans[trie.query(0,num,1ll*32)]<<endl;
    }
    return 0;
}
