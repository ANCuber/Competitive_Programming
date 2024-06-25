#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int ans = 0;
string s;

int dfs(int u, int l, int cnt) {
    for (int i = 1; i <= 4; ++i) {
        if (s[u+i+cnt] == '2') {
            cnt += dfs(u+i+cnt,l>>1,0);
        } else {
            ans += (l>>1)*(l>>1)*(s[u+i+cnt]-'0');
            //cout<<u+i+cnt<<' '<<l/2<<' '<<s[u+i+cnt]<<'\n';
        }
    }
    return cnt+4;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>s;
    int n; cin>>n;
    if (s.size() == 1) {
        cout<<(s[0]-'0')*n*n<<'\n';
        return 0;
    }
    dfs(0,n,0);
    cout<<ans<<'\n';
    return 0;
}
