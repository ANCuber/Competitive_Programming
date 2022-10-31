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
    string s; cin>>s;
    int ans = 1, rep = 1;
    for (int i = 1; i < s.size(); ++i) {
        rep = (s[i]==s[i-1])?(rep+1):1;
        ans = max(rep,ans);
    }
    printf("%d\n",ans);
    return 0;
}
