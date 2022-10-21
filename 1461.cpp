#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m, x;
string i;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    while(cin>>n>>m && (n+m)) {
        string s = "!";
        while(n--) {
            cin>>i;
            s += i;
        }
        while(m--) {
            cin>>x;
            cout<<s[x];
        }
        cout<<endl;
    }
    
    return 0;
}
