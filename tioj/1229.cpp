#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l, n, m;
    cin>>l>>n>>m;
    vector<int> a(n);
    for (auto& i : a) {
        cin>>i;
        i--;
    }
    string x;
    while(l--) {
        cin>>x;
        while(x.size() < n) x.push_back('#');
        for (int i = 0; i < m; ++i) {
            string cur = x;
            for (int j = 0; j < n; ++j) {
                x[a[j]] = cur[j];
            }
        }
        cout<<x<<endl;
    }
    return 0;
}
