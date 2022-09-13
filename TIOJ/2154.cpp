#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    string s;
    int cur = (1<<26)-1;
    for (int j = 0; j < n; ++j) {
        cin>>s;
        int now = 0;
        for (auto i : s) {
            now |= (1<<(i-'a'));
        }
        cur &= now;
    }
    if (cur) {
        cout<<char('a'+__lg(cur&-cur));
    } else {
        cout<<7122<<endl;
    }
    return 0;
}
