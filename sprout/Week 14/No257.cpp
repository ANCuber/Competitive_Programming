#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Nd{
    int lat = 0;
    int val;
    int ori;
    bool reset = 0;
};

vector <Nd> seg;

int init(int l, int r, int node) {
    if (l == r) {
        seg[node].val = seg[node].ori = 1;
        return 1;
    }
    int mid = (l+r)/2;
    return seg[node].val = seg[node].ori = init(l,mid,node<<1)+init(mid+1,r,(node<<1)|1);
}

int turn(int ql, int qr, int l, int r, int node) {
    
}

int reset(int ql, int qr, int l, int r, int node) {

}

int query(int ql, int qr, int l, int r, int node) {

}

int main() {
    int n, m; cin>>n>>m;
    seg.resize(n<<1);
    init(1,n,1);
    while(m--) {
        string cmd; cin>>cmd;
        int a, b; cin>>a,b;
        if (cmd[0] == 'T') {

        } else if (cmd[0] == 'R') {

        } else {

        }
    }
    return 0;
}