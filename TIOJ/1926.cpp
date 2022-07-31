#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include "lib1926.h"
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

ll dx[4] = {0,0,1,-1};
ll dy[4] = {1,-1,0,0};
ll mid, n, m;

bool check(ll x, ll y) {
    bool flag = 1;
    for (ll i = 0; i < 4; ++i) {
        if (x+dx[i] < 0 || x+dx[i] >= n || y+dy[i] < 0 || y+dy[i] >= m) continue;
        if (!Oshietekudasai(x,y,x+dx[i],y+dy[i])) {
            flag = 0;
        }
    }
    return flag;
}

ll query(ll l, ll r) {
    if (l == r) return l;

    ll m = r+(l-r)/2;
    ll ls = query(l,m), rs = query(m+1,r);
    if (Oshietekudasai(mid,ls,mid,rs)) return ls;  
    else return rs;
}

int main() {
    Init(&n,&m);
    ll l = 0, r = m;
    mid = r+(l-r)/2;
    while(true) {
        ll minn = query(0,n-1);
        if (check(mid,minn)) {
            Report(mid,minn);
            return 0;
        }
        if (Oshietekudasai(mid,minn,mid+1,minn)) r = mid;  
        else l = mid;
        mid = r+(l-r)/2;
    }
    return 0;
}
