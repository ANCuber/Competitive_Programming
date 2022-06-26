#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m;
    while(cin>>m) {
        int a;
        priority_queue<int> p1,p2;
        for (int i = 0; i < m; ++i) {
            cin>>a;
            p1.push(a);
        }
        for (int i = 0; i < m; ++i) {
            cin>>a;
            p2.push(a);
        }
        ll ans = 0;
        while(!p1.empty()) {
            ans += p1.top()*p2.top();
            p1.pop();
            p2.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}