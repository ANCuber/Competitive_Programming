#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

pii Turn(string x) {
    int a = 0, b = 0, flg;
    for (int i = 1; i < x.size(); ++i) {
        if (x[i] == '.') {
            flg = 1;
            continue;
        }
        if (!flg) {
            a = 10*a+(x[i]-'0');
        } else {
            b = 10*b+(x[i]-'0');
        }
    }
    return {a,b};
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    string mny; cin>>mny;
    pii cur = Turn(mny);
    int a = cur.first, b = cur.second;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin>>mny;
        cur = Turn(mny);
        a += cur.first, b += cur.second;
        if (b >= 100) {
            a += b/100;
            b = b%100;
        }
        if (!b) cnt++;
    }
    cout<<n-cnt<<endl;
    return 0;
}
