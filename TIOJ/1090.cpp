#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, st; cin>>n>>st;
    set <int> s;
    int p;
    for (int i = 0; i < n; ++i) {
        cin>>p;
        s.insert(p);
    }
    int cur = st;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        
    }
    cout<<ans<<endl;
    return 0;
}
