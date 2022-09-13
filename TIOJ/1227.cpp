#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

struct SEG{
    ll arr[1e6+5];
    
} seg[2];

void init(int n, ll d[]) {
    int sz = (n+1)>>1;
    
}

void change(int a, int b, ll k) {
    
}

ll query(int p) {
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q, a, b, p;
    cin>>n>>m>>q;
    ll k, d[n+5];
    for (int i = 0; i < n; ++i) cin>>d[i];
    init(n,d);
    while(m--) {
        cin>>a>>b>>k;
        change(a,b,k);
    }
    while(q--) {
        cin>>p;
        cout<<query(p)<<endl;
    }
    return 0;
}
