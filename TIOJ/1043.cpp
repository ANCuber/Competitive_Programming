#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, p;
    ll ans = 0;
    while(cin>>n>>p && n && p) {
        ans = 0;
        vector <int> k(n); 
        for (int i = 0; i < n; ++i) {
            cin>>k[i];
        }
        sort(k.begin(),k.end());
        if (k[0] > n) {
            cout<<0<<endl;
            continue;
        }

    }
    return 0;
}
