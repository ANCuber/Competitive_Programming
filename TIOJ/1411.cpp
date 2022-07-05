#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

vector<ll> a;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n) {
        a.assign(n+1,0);
        ll sum = 0;
        int p = 0;
        for (int i = 1; i <= n; ++i) {
            cin>>a[i];
            sum += a[i];
        }
        if (!sum) cout<<n<<endl;
        
    }
    return 0;
}
