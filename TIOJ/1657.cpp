#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    while(cin>>n>>m) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (j!=1) cout<<' ';
                cout<<i<<'*'<<j<<'='<<i*j;
            }
            cout<<endl;
        }
    }
    return 0;
}
