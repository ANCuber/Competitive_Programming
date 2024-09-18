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
    string s; cin>>s;    
    int n, mx = 0; cin>>n;
    while(n--) {
        string t; cin>>t;
        mx = -1;
        int tsz = t.size(), ssz = s.size();
        for (int i = max(0,ssz-tsz); i < ssz; ++i) {
            int flag = 0;
            for (int j = i; j < ssz; ++j) {
                if (s[j] != t[j-i]) flag = 1;
            }
            if (!flag) mx = max(mx,min(ssz-i,tsz-ssz+i));
        }
        cout<<mx<<endl;
    }
    return 0;
}
