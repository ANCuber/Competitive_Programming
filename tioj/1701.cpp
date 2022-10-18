#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    while(cin>>s) {
        int ans = 0;
        for (int i = 1; i <= s.size(); ++i) {
            if (s.size() % i == 0) {
                int ctrl = 1;
                for (int j = i; j < s.size(); j += i) {
                    for (int k = 0; k < i; ++k) {
                        if (s[k] != s[j+k]) ctrl = 0;
                    }
                }
                if (ctrl) {
                    ans = s.size()/i;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
