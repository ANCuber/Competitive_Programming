#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    string x;
    ll ans = 0;
    while(n--) {
        cin>>x;
        if (x[2] == x[3] && x[2] == x[3] && x[3] == x[4] && x[4] == x[5]) {
            ans += 2000;
        } else if (x[2] == x[3] && x[4] == x[5]) {
            ans += 1500;
        } else {
            ans += 1000;
        }
    }
    cout<<ans<<endl;
    return 0;
}
