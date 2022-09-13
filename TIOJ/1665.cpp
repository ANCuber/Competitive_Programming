#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x;
    while(cin>>x) {
        int ans = 0;
        while(x) {
            x /= 10;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
