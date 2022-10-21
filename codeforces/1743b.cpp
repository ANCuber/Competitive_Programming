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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if (n == 1) {cout << 1 << endl; continue;}
        cout << 1 << " " << n << " ";
        for (int i = 2; i < n; ++i) cout << i << " ";
        cout << endl;
    }
    
    return 0;
}
