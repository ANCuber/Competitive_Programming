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
    int base = 100;
    for(int i = 1; i <= 80; ++i) {
        cout<<base%49;
        base = base%49;
        if (base < 4) base *= 100;
        else base *= 10;
    }
    
    return 0;
}
