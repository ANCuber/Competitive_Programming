#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int arr[500005];
vector <pair<int,int> > sg;

pii init(int l, int r, int node) {
    if (l == r) {
        sg[node].first = arr[l];
        sg[node].second = 1;
        return sg[node];
    }
    int mid = (l+r)>>1;
    pii lp = init(l,mid,node<<1);
    pii rp = init(mid+1,r,(node<<1)+1);
    if (lp.first == rp.first) {
        sg[node].first = lp.first;
        sg[node].second = lp.second+rp.second;
    } else {
        if (lp.second >= rp.second) {
            sg[node].first = lp.first;
            sg[node].second = lp.second-rp.second;
        } else {
            sg[node].first = rp.first;
            sg[node].second = rp.second-lp.second;
        }
    }
    return sg[node];
}

pii query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && r <= qr) {
        return sg[node];
    }
    int mid = (l+r)>>1;
    if (qr <= mid) {
        return query(ql,qr,l,mid,node<<1);
    } 
    if (ql > mid) {
        return query(ql,qr,mid+1,r,(node<<1)+1);
    }
    pii lp = query(ql,qr,l,mid,node<<1);
    pii rp = query(ql,qr,mid+1,r,(node<<1)+1);
    pii ret;
    if (lp.first == rp.first) {
        ret.first = lp.first;
        ret.second = lp.second+rp.second;
    } else {
        if (lp.second >= rp.second) {
            ret.first = lp.first;
            ret.second = lp.second-rp.second;
        } else {
            ret.first = rp.first;
            ret.second = rp.second-lp.second;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin>>n>>q;
    vector <vector<int> > pos(500005);
    sg.resize(n<<2);
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        pos[arr[i]].push_back(i);
    }
    init(1,n,1);
    while(q--) {
        int l, r;
        cin>>l>>r;
        pii pa = query(l,r,1,n,1);
        //cout<<pa.first<<endl;
        auto al = lower_bound(pos[pa.first].begin(),pos[pa.first].end(),l);
        auto ar = upper_bound(pos[pa.first].begin(),pos[pa.first].end(),r);
        int count = ar-al;
        //cout<<count<<endl;
        if (count > ((r-l+1)>>1)) {
            cout<<pa.first<<endl;
        } else {
            cout<<0<<endl;
        }
    }
    return 0;
}

//1 1 3 2 3 4 3