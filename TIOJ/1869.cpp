#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

int n;
vector<vector<int> > bit;

void add(int x, int y, int v) {
    for (int i = x; i <= n; i += (i&(-i))) {
        for (int j = y; j <= n; j += (j&(-j))) {
            bit[i][j] += v;
        }
    }
}

ll query(int x, int y) {
    ll sum = 0;
    for (int i = x; i > 0; i -= (i&(-i))) {
        for (int j = y; j > 0; j -= (j&(-j))) {
            sum += bit[i][j];
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    int cmd;
    int x, y;
    int z;
    int x1, y1, x2, y2;
    bit.assign(n+1,vector<int>(n+1,0));
    while(cin>>cmd) {
        if (cmd == 1) {
            cin>>x>>y>>z;
            add(++x,++y,z);
        } else {
            cin>>x1>>y1>>x2>>y2;
            x1++, y1++, x2++, y2++;
            ll lrg = query(x2,y2);
            ll mns = query(x1-1,y2)+query(x2,y1-1);
            mns -= query(x1-1,y1-1);
            cout<<lrg-mns<<endl;
        }
    }
    return 0;
}
