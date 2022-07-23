#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string x; cin>>x;
    ll base = 1;
    ll num = 0;
    ll unk;
    for (int i = x.size()-1; i >= 0; --i) {
        if (x[i] == '?') {
            unk = base;
        } else {
            num += base*(x[i]-'0');
        }
        base *= 10;
    }
    for (ll i = 0; i < 10; ++i) {
        if ((num+i*unk) % 7 == 0) {
            cout<<num+i*unk<<endl;
        }
    }
    return 0;
}
