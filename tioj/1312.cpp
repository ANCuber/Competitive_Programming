#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

vector <int> boss;

int fb(int x) {
    if (x == boss[x]) return x;
    return boss[x] = fb(boss[x]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; 
    while(cin>>n>>m) {
        boss.assign(n+1,0);
        for (int i = 1; i <= n; ++i) boss[i] = i;
        int a, b;
        while(m--) {
            cin>>a>>b;
            int aaa = fb(a);
            int bbb = fb(b);
            boss[aaa] = boss[bbb] = min(bbb,aaa);
        }
        int k; cin>>k;
        cout<<fb(k)<<endl;
    }
    return 0;
}
