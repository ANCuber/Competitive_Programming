#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        vector< pii > c(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin>>c[i].first>>c[i].second;
            sum += c[i].second;
        }
        if (m > sum) cout<<"so sad"<<endl;
        else {
            int price = 0;
            sort(c.begin(),c.end());
            for (auto i : c) {
                price += min(m,i.second)*i.first;
                m -= i.second;
                if (m<=0) break;
            }
            cout<<price<<endl;
        }
    }
}
