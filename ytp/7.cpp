#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    int x, y;
    for (int i = 0; i < n-1; ++i) {
        cin>>x>>y;
        cout<<i+1<<endl;
    }
    bitset <200000> bs;
    bs.reset();

    for (int i = n-1; i < m; ++i) {
        cin>>x>>y;
            for (int i = min(x,y); i < max(x,y); ++i) {
                bs[i] = 1;
            }
        cout<<n-1-bs.count()<<endl;
    }
    return 0;
}
