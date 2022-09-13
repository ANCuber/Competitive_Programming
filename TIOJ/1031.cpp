#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>

int ans;

void solve(int a) {
    if (a == 1) {
        ans++;
        return;
    } else if (a == 2 || a == 3) {
        ans += 2;
        return;
    }
    int base = 1;
    while(true) {
        a>>=1;
        base<<=1;
        if (a == 2 || a == 3) {
            ans += (base<<1);
            break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a;
    while(cin>>a && a) {
        ans = 0;
        solve(a);
        while(cin>>a) {
            if (a == 0) break;
            solve(a);
        }
        cout<<ans<<endl;
    }
    return 0;
}
