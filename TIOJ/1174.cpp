#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    vector<int> a(n);
    set <int> s;
    int b;
    for (int i = 0; i < n; ++i) cin>>a[i];
    for (int i = 0; i < m; ++i) {
        cin>>b;
        s.insert(b);
    }
    int minn = 1e9;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= *s.begin()) minn = min(minn,*s.begin()-a[i]);
        else if (a[i] >= *s.rbegin()) minn = min(minn,a[i]-*s.rbegin());
        else {
            auto it = s.lower_bound(a[i]);
            minn = min(minn,*it-a[i]);
            it--;
            minn = min(minn,a[i]-*it);
        }
    }
    cout<<minn<<endl;
    return 0;
}
