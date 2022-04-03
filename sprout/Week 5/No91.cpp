#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        long long n; cin>>n;
        if (n == 1) {
            cout<<1<<'\n';
            continue;
        }
        deque <int> ans;
        for (int i = 9; i >= 2; --i) {
            while (!(n%i)) {
                ans.push_front(i);
                n /= i;
            }
        }
        if (n != 1) cout<<-1;
        else {
            for (auto i : ans) cout<<i;
        }
        cout<<'\n';
    }
    return 0;
}