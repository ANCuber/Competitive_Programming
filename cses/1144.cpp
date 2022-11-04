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
    multiset<int> s;    
    int n, q, a, b;
    cin>>n>>q;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        s.insert(arr[i]);
    }
    char cmd;
    while(q--) {
        cin>>cmd>>a>>b;
        if (cmd == '!') {
            s.erase(s.find(arr[a]));
            arr[a] = b;
            s.insert(b);
        } else {
            
        }
    }
    return 0;
}
