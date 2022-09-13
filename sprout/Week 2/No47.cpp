#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    set <int> p;
    for (int l = 1; l <= n; ++l) {
        string c; cin>>c;
        int x; cin>>x;
        if (c[0] == 'i') {
            p.insert(x);
        } else if (c[0] == 'd') {
            p.erase(x);
        } else {
            if (*p.begin() >= x) {
                cout<<*p.begin()<<'\n';
                continue;
            } else if (*p.rbegin() <= x) {
                cout<<*p.rbegin()<<'\n';
                continue;
            }
            int a = *p.lower_bound(x) - x;
            int b = x - *prev(p.lower_bound(x));
            if (a == 0) {
                cout<<*p.lower_bound(x)<<'\n';
                continue;
            }
            if (a > b) cout<<*prev(p.lower_bound(x))<<'\n';
            else if (a < b) cout<<*p.lower_bound(x)<<'\n';
            else {
                cout<<*prev(p.lower_bound(x))<<' ';
                cout<<*p.lower_bound(x)<<'\n';
            }
        }
    }
    return 0;
}