#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    while(cin>>s) {
        int cnt = 0;
        for (auto c : s) {
            if ('a' <= c && c <= 'z') {
                cnt += c-'a'+1;
            } else {
                cnt += c-'A'+1;
            }
            cnt %= 17;
        }
        if (cnt <= 2) cout<<"D\n";
        else if (cnt <= 5) cout<<"C\n";
        else if (cnt <= 9) cout<<"B\n";
        else if (cnt <= 12) cout<<"A\n";
        else cout<<"SA\n";
    }
    return 0;
}
