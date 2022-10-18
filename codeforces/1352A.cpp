#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int mx = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            int a; cin>>a;
            if (mx < a) {
                ans = i;
                mx = a;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
