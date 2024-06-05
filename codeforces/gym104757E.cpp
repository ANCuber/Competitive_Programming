#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s; cin>>s;
    int vld = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (i && s[i] == s[i-1] && s[i] == 'O') vld = 0;
        if (s[i] != 'O' && s[i] != 'E') vld = 0;
        if (i == s.size()-1 && s[i] != 'O') vld = 0;
    }
    if (!vld) {
        cout<<"INVALID\n";
        return 0;
    }
    for (int i = 0; i <= 47; ++i) {
        int cur = (1<<i), j;
        for (j = s.size()-1; j >= 0; --j) {
            if (s[j] == 'E') {
                cur *= 2;
            } else if (s[j] == 'O') {
                cur = (cur-1);
                if (cur%3 || (cur/3)%2 == 0) break;
                cur /= 3;
            }
        }
        if (j == -1) {
            cout<<cur<<endl;
            return 0;
        }
    }
    return 0;
}
