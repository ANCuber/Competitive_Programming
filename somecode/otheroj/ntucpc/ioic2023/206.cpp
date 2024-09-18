#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

vector<int> pri;
const int mxn = 1e6;
vector<int> is(mxn+5,1);

void findprime() {
    is[1] = 0;
    for (int i = 2; i <= mxn; ++i) {
        if (!is[i]) continue;
        pri.pb(i);
        for (int j = i+i; j <= mxn; j += i) {
            is[j] = 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    findprime();
    while(t--) {
        int x; cin>>x;
        for (int i = 2; i <= x-2; ++i) {
            if (is[i] && is[x-i]) {
                cout<<i<<' '<<x-i<<endl;
                break;
            }
        }
    }
    
    return 0;
}
