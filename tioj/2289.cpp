#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, q;

struct Range{
    int l, r;
    bool operator<(Range b) {
        if (l == b.l) return r < b.r;
        return l < b.l;
    }
};

signed main() {
    scanf("%d%d",&n,&q);
    vector<Range> rg(q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d",&rg[i].l,&rg[i].r);
        
    }
    
    return 0;
}
