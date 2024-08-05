#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int crt(string x) {
    int ret = 0;
    for (int i = 0; i < x.size(); ++i) {
        ret *= 10;
        ret += (x[i]-'0');
    }
    return ret;
}

int power(int x) {
    int ret = 1;
    for (int i = 0; i < x; ++i) ret *= 10;
    return ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string N; cin>>N;
    int L = 0;
    vector<pair<int,int> > R;
    while(L < N.size()) {
        for (int i = )
    }
    for (int i = 1; i < N.size(); ++i) {
        if (N[i] == '1' && N[i-1] != '9') {
            R.pb({L,i-1});
            L = i;
            cout<<L<<' '<<i<<endl
        }
    }
    vector<int> ans;
    for (int i = 1; i < R.size(); ++i) {
        int mx = power(R[i].second-R[i].first-1)*2;
        int cur = crt(N.substr(R[i].first,R[i].second+1));
        for (int j = 0; j < R[i].second-R[i].first; ++i) {
            ans.pb((mx-cur)/(mx/2));
            mx /= 10;
        }
    }
    int flag = 0;
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] != 0) flag = 1;
        if (!flag) continue;
        cout<<ans[i];
    }
    cout<<'\n';

    return 0;
}
