#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

vector <int> st;

vector <vector<int> > id;

void update(int l, int r, int node, int tar) {
    if (l == r) {
        st[node]++;
        return;
    }
    int mid = (l+r)>>1;
    if (tar <= mid) {
        update(l,mid,node<<1,tar);
    } else {
        update(mid+1,r,(node<<1)+1,tar);
    }
    st[node]++;
    return;
}

int query(int node, int ql, int qr, int l, int r) {
    if (ql <= l && r <= qr) {
        return st[node];
    }
    int mid = (l+r)>>1;
    if (qr <= mid) return query(node<<1,ql,qr,l,mid);
    if (ql > mid) return query((node<<1)+1,ql,qr,mid+1,r);
    return query(node<<1,ql,qr,l,mid) + query((node<<1)+1,ql,qr,mid+1,r);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    st.resize(n<<3,0); 
    id.resize(n+1);
    for (int i = 1; i <= (n<<1); ++i) {
        int a; cin>>a;
        id[a].push_back(i);
    }
    ll ans = 0;
    update(1,n<<1,1,id[1][0]);
    update(1,n<<1,1,id[1][1]);
    for (int i = 2; i <= n; ++i) {
        int l = id[i][0];
        int r = id[i][1];
        ans += (ll)query(1,l,r,1,n<<1);
        update(1,n<<1,1,l);
        update(1,n<<1,1,r);
    }
    cout<<ans<<endl;
    return 0;
}