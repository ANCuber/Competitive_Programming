#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    if (n == 1) {
        int x; cin>>x;
        cout<<x<<endl;
        return 0;
    }
    n -= 2;
    int x;
    int a, b; cin>>a>>b;
    int tmp = __gcd(a,b);
    while(n--) {
        cin>>x;
        tmp = __gcd(tmp,x);
    }
    cout<<tmp<<endl;
    return 0;
}
