#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector <ll> segtree;
vector <int> segid;
vector <ll> arr;

ll minn;
int miid;

void build(int l, int r, int index) {
    if (l == r) {
        segtree[index] = arr[l];
        segid[index] = l;
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,index<<1);
    build(mid+1,r,(index<<1)+1);
    if (segtree[index<<1] < segtree[(index<<1)+1]) {
        segtree[index] = segtree[index<<1];
        segid[index] = segid[index<<1];
    } else {
        segtree[index] = segtree[(index<<1)+1];
        segid[index] = segid[(index<<1)+1];
    }
}

void query(int l, int r, int index, int ql, int qr) {
    if (ql <= l && r <= qr) {
        if (segtree[index] < minn) {
            minn = segtree[index];
            miid = segid[index];
        }
        return;
    }
    int mid = (l+r)>>1;
    if (ql <= mid) {
        query(l,mid,index<<1,ql,qr);
    } 
    if (mid < qr){
        query(mid+1,r,(index<<1)+1,ql,qr);
    }
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    arr.resize(n+1);
    vector <ll> presum(n+1,0);
    segtree.resize(4*n);
    segid.resize(4*n);
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        presum[i] = presum[i-1]+arr[i];
    }
    build(1,n,1);
    int l = 1;
    int r = n;
    while(r-l > 0) {
        minn = 1e12;
        query(1,n,1,l,r);
        
        ll l_sum = presum[miid-1]-presum[l-1];
        ll r_sum = presum[r]-presum[miid];
        if (l_sum <= r_sum) {
            l = miid+1;
        } else {
            r = miid-1;
        }
    }
    cout<<arr[l]<<endl;
    return 0;
}