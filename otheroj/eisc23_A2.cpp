#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string inp; cin>>inp;
    string x = "", y = "";
    int flag = 0;
    for (int i = 0; i < inp.size(); ++i) {
        if (inp[i] == '.') {
            flag = 1;
            continue;
        }
        if (!flag) x = x+inp[i];
        else y = y+inp[i];
    }
    int q = 0, p = 0;
    for (int i = 0; i < y.size(); ++i) {
        q *= 10, q += 9;
        p *= 10, p += y[i]-'0';
    }
    if (!p) {
        cout<<x<<'/'<<1<<endl;
    } else {
        int gcd = __gcd(p,q);
        p /= gcd, q /= gcd;
        int num = stoi(x);
        cout<<(num*q+p)<<'/'<<q<<endl;
    }
    return 0;
}
