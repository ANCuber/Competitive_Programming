#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

vector<int> boss;

int fb(int x) {
    if (x == boss[x]) return x;
    return boss[x] = fb(boss[x]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;
    boss.resize(n+1);
    for (int i = 0; i <= n; ++i) boss[i]=i;
    string cmd;
    int a, b, x;
    while(q--) {
        cin>>cmd;
        if (cmd[0] == 'M') {
            cin>>a>>b;
            boss[fb(b)] = fb(a);
        } else {
            cin>>x;
            cout<<fb(x)<<endl;
        }
    }
    return 0;
}
