#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector <int> w(n);
    vector <int> l(n-1);
    for (int i = 0; i < n; ++i) cin>>w[i];
    for (int i = 0; i < n-1; ++i) cin>>l[i];
    sort(w.begin(),w.end());
    sort(l.begin(),l.end(),greater<int>());
    int sum = w[0];
    int c = 0;
    for (int i = 0; i < n-1;) {
        c += sum*l[i];
        sum += w[++i];
    }
    cout<<c<<endl;
    return 0;
}
