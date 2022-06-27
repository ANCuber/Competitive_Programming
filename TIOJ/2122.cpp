#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Nd{
    
};

vector<int> arr;
vector<Nd> seg;
int ql, qr;

void mg(Nd &tar,const Nd lt,const Nd rt) {
    
}

void init(int l, int r, int node) {
    if (l == r) {
        
    }
    int mid = (l+r)>>1;
    init(l,mid,node<<1);
    init(mid+1,r,(node<<1)|1);
    
}

Nd query(int l, int r, int node) {
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin>>n>>q;
    arr.resize(n+1);
    seg.resize(n<<2);
    vector<vector<int> > p(100005);
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        p[arr[i]].emplace_back(i);
    }
    init(1,n,1);
    while(q--) {
        cin>>ql>>qr;
        
    }
    return 0;
}