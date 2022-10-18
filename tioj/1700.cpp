#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n) {
        int a, b, tmp;
        if (n == 1) {
            cin>>a;
            cout<<a<<endl;
            continue;
        }
        cin>>a>>b;
        tmp = __gcd(a,b);
        n -= 2;
        while(n--) {
            cin>>a;
            tmp = __gcd(tmp,a);
        }
        cout<<tmp<<endl;
    }
    return 0;
}
