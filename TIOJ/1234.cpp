#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pii pair<int,int> 

bool cmp(pii a, pii b) {
    return a.first*b.second < a.second*b.first;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector< pii > v;
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (__gcd(i,j) == 1) {
                v.push_back({i,j});
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    cout<<v.size()<<endl;

    if (v.size() >= n) cout<<v[n-1].first<<'/'<<v[n-1].second<<endl;
    else cout<<v.back().first<<'/'<<v.back().second<<endl;

    return 0;
}
