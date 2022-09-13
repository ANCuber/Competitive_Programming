#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n && n) {
        vector <pii> tv(n);
        for (int i = 0; i < n; ++i) {
            cin>>tv[i].first>>tv[i].second;
        }
        int maxn = -1;
        int a = 1e9, b = 1e9;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                int cur = (tv[i].first-tv[j].first)*(tv[i].first-tv[j].first);
                cur += (tv[i].second-tv[j].second)*(tv[i].second-tv[j].second);
                if (cur > maxn) {
                    a = i, b = j;
                    maxn = cur;
                }
            }
        }
        cout<<a<<' '<<b<<endl;
    }
    return 0;
}
