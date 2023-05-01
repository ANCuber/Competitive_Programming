#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

struct SEG{
    vector<int> x, hp;
    void setup(int l, int r, int p, vector<int> &arr) {
        if (l == r) {
            x[p] = arr[l];
            hp[p] = 1;
            return;
        }
        setup(l,mid,p<<1,arr), setup(mid+1,r,p<<1|1,arr);
    }
    void init(int _n, vector<int> &arr) {
        x.assign(_n<<2,0);
        hp.assign(_n<<2,0);
        setup(1,_n,1,arr);
    }
    void mdf(int l, int r, int p, int q, int v) {
        
    }
    void div(int l, int r, int p, int ql, int qr, int k) {
        
    }
} seg;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    vector<int> arr(n+2);
    for (int i = 1; i <= n; ++i) cin>>arr[i];
    int c, l, r, k;
    while(cin>>q) {
        cin>>c>>l>>r;
        if (c == 1) {
            
        } else if (c == 2) {
            cin>>k;
            if (k != 1) 
        } else {
            
        }
    }
    
    return 0;
}
