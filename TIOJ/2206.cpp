#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector <int> v(n+5);
    for (int i = 1; i <= n; ++i) cin>>v[i];
    int q; cin>>q;
    while(q--) {
        int a, b; cin>>a>>b;
        for (int i = 1; i <= b; ++i) {
            a = v[a];
        }
        cout<<a<<endl;
    }
    return 0;
}
