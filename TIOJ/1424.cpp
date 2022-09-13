#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    priority_queue <int,vector<int>,greater<int> > s;
    for (int i = 0; i < n; ++i) {
        int a; cin>>a;
        s.push(a);
    }
    ll ans = 0;
    while(true) {
        if (s.size() == 1) {
            break;
        }
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        ans += (a+b);
        s.push(a+b);
    }
    cout<<ans<<endl;
    return 0;
}