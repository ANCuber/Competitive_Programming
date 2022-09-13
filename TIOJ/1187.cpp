#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n && n) {
        int sum = 0, a, mx = -1, mn = 11;
        for (int i = 0; i < n; ++i) {
            cin>>a;
            sum += a;
            mx = max(mx,a), mn = min(mn,a);
        }
        sum -= (mx+mn);
        long double x = sum*1.0, y = (n-2)*1.0;
        cout<<fixed<<setprecision(2)<<x/y<<endl;
    }
    return 0;
}
