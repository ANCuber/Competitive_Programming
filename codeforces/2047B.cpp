#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--) {
        map<char,int> mp;
        int n; cin>>n;
        string s; cin>>s;
        for (auto &i : s) mp[i]++;
        char mnc, mxc;
        int mn = 100, mx = -1;
        for (auto &[i,j] : mp) {
            //cout<<">> "<<i<<' '<<j<<endl;
            if (j > mx) {
                mx = j;
                mxc = i;
            }
            if (j < mn) {
                mn = j;
                mnc = i;
            }
        }
        //cout<<">>> "<<mnc<<' '<<mxc<<endl;
        if (mxc == mnc) {
            for (auto &i : s) {
                if (i != mnc) {
                    i = mnc;
                    break;
                }
            }
        } else {
            for (auto &i : s) {
                if (i == mnc) {
                    i = mxc;
                    break;
                }
            }
        }
        cout<<s<<'\n';
    }
    return 0;
}
