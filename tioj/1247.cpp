#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, cas = 0;

void Run() {
    vector<int> x(n+1);
    int flag = 1;
    for (int i = 1; i <= n; ++i) cin>>x[i];
    for (int i = 1; i <= n; ++i) {
        sort(x.begin()+i,x.end(),greater<int>());
        if (x[i] > n-i) {
            flag = 0;
            break;
        }
        for (int j = 1; j <= x[i] && flag; ++j) {
            if (x[i+j] <= 0) flag = 0;
            x[i+j]--;
        }
        if (!flag) break;
    }
    cout<<"Case #"<<(++cas)<<":";
    if (flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n && n) Run();
    return 0;
}
