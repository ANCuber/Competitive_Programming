#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int dis(int x1, int y1, int x2, int y2) {
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, r; cin>>n>>r;
    int x, y;
    map< pii, int > mp;
    while(n--) {
        cin>>x>>y;
        int tx = x, ty = y;
        x-=r, y+=r;
        for (int i = 0; i <= 2*r; ++i) {
            for (int j = 0; j <= 2*r; ++j) {
                if (dis(tx,ty,x+i,y-j) <= r*r) {
                    mp[{x+i,y-j}]++;
                }
            }
        }
    }
    auto iter = mp.begin();
    int cnt = 0;
    for (;iter != mp.end(); ++iter) {
        if ((iter->second)&1) {
            //cout<<iter->first.first<<' '<<iter->first.second<<endl;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
