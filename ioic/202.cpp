#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define db double

struct node{
    db a, b;
    db val(db x) {
        return a*x+b;
    }
}seg [];

void insert(int l, int r, int p, int node) {
    
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q; cin>>q;    
    int c, a, b, k, sz = 0;
    while(q--) {
        cin>>c;
        if (c == 0) {
            cin>>a;
            if (!sz) cout<<"double is good at problem setting\n";
            else {
                
            }
        } else if (c == 1) {
            cin>>a>>b;
            
        } else {
            cin>>k;
            
        }
    }
    
    return 0;
}
