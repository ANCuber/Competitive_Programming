#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    int lg = -1, cnt = 0, tn = n, bs = 5;
    while(tn) {
        lg++;
        tn /= 5;
    }
    for (int i = 1; i <= lg; ++i) {
        cnt += n/bs;
        bs *= 5;
    }
    cout<<cnt<<endl;
    return 0;
}
