#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

vector <int> bs, gp;
int n, k;
int d, x, y;

int fb(int p) {
    if (bs[p] == p) return p;
    return bs[p] = fb(bs[p]);
}

bool check() {
    cin>>d>>x>>y;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    bs.resize(n+1);
    gp.assign(n+1,0);
    for (int i = 1; i <= n; ++i) bs[i] = i;

    int ans = 0;
    while(k--) {
        ans += !check();
    }
    cout<<ans<<endl;
    return 0;
}
