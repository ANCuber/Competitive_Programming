#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void Run() {
    string s; cin>>s;
    if (s.size() <= 1) {
        cout<<1<<endl;
        return;
    }
    s = s+s.back();
    int ans = 0, pid = 0;
    char pre = s[0];
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i-1]) {
            ans++;
            if (pid < i-1 && s[i-1] == pre) ans++;
            pre = s[i];
            pid = i;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin>>N;    
    while(N--) Run();
    return 0;
}
