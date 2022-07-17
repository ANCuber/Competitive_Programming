#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    multiset <int> s;
    while(cin>>n && n) {
        if (n == -1) {
            if (s.empty()) continue;
            cout<<*s.begin()<<' ';
            s.erase(s.begin());
        } else if (n == -2) {
            if (s.empty()) continue;
            auto it = s.end();
            it--;
            cout<<*it<<' ';
            s.erase(it);
        } else {
            s.insert(n);
        }
    }
    return 0;
}
