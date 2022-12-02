//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int n;
double mid;
ll k;
multiset <ll> lst, rst;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout<<fixed<<setprecision(6);
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>k;
        if (!i) {
            lst.insert(k);
            mid = k;
            cout<<mid<<endl;
            continue;
        }
        
        if (i&1) {//even
            if (*lst.rbegin() <= k) {
                rst.insert(k);
            } else {
                rst.insert(*lst.rbegin());
                lst.erase(lst.find(*lst.rbegin()));
                lst.insert(k);
            }
            mid = ((*lst.rbegin())+(*rst.begin()))/2.0;
            cout<<mid<<endl;
        } else {
            if (*rst.begin() >= k) {
                lst.insert(k);
            } else {
                lst.insert((*rst.begin()));
                rst.erase(rst.find(*rst.begin()));
                rst.insert(k);
            }
            mid = (*lst.rbegin());
            cout<<mid<<endl;
        }
    }
    return 0;
}
