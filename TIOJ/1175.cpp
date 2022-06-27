#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    set <int> lis;
    for (int i = 0; i < n; ++i) {
        int a; cin>>a;
        lis.insert(a);
        auto iter = lis.upper_bound(a);
        if (iter != lis.end()) lis.erase(iter);
    }
    cout<<lis.size()<<endl;
    return 0;
}