#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'
#define int ll

struct shop{int x, y, z;};

int dis(shop a, shop b) {
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    int x, y, z, ans = 0;
    vector<shop> sp(n);
    vector<bool> v(n,0);
    vector<int> d(n,LONG_LONG_MAX);
    
    cout<<ans<<endl;
    return 0;
}
