#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int power(int x, int n) {
     int ans = 1, base = x;
     while(n) {
         if (n&1) ans *= base;
         base *= base;
         n >>= 1;
     }
     return ans;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b; cin>>a>>b;
    cout<<power(a,b)<<endl;
}
