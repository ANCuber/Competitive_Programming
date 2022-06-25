#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Nd{
    int x;
    int hp;
    int tag = 0;
};

vector <int> arr;
vector <Nd> seg;
vector <int> win;
int ql, qr;

void init(int l, int r, int p) {
    if (l == r) {
        seg[p].x = l;
        seg[p].hp = arr[l];
        return;
    }
    int mid = (l+r)>>1;
    init(l,mid,p<<1);
    init(mid+1,r,p<<1|1);
    
}

void push(int p, int d) {
    
}

void chg() {

}

void add(int l, int r, int p, int k) {

}

int query(int l, int r, int p) {
    
}

int main() {
    int n, m; cin>>n>>m;
    arr.resize(n+1);
    seg.resize(n<<1|1);
    win.assign(n<<1|1,0);
    for (int i = 1; i <= n; ++i) cin>>arr[i];
    init(1,n,1);
    int cmd, k;
    while(m--) {
        cin>>cmd;
        cin>>ql>>qr;
        if (cmd == 1) {
            cin>>k;
            add(1,n,1,k);
            
        } else {

        }
    }
    return 0;
}