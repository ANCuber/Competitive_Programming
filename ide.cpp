#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 2000; ++i) {
        int cur = 18*i*i-2;
        if ((int(sqrt(cur)))*(int(sqrt(cur))) == cur) {
            cout<<'('<<int(sqrt(cur))<<','<<i<<')'<<endl;
        }
    }
    
    return 0;
}
