#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    bitset<1005> bs;
    bs.reset();
    int n, k, p; cin>>n>>k>>p;    
    int r = n-k-p;
    if (r > p) swap(r,p);
    if (r == 0) {
        if (k != p) cout<<0<<endl;
        else {
            if (k <= 2) cout<<1<<endl;
            else cout<<0<<endl;
        }
    } else {
        if (r != p && p != k && k != r) cout<<0<<endl;
        else if (r == k && k < p) {
            if (k <= 2) cout<<1<<endl;
            else cout<<0<<endl;
        } else if (r < k && k == p) {
            if (k == 2) cout<<2<<endl;
            else if (k == 3) {
                if (r == 1) cout<<1<<endl;
                else cout<<2<<endl;
            } else if (k == 4) {
                if (r == 2) cout<<0<<endl;
                else cout<<1<<endl;
            } else {
                cout<<0<<endl;
            }
        } else if (r == p && p < k) {
            if (p <= 2) cout<<1<<endl;
            else cout<<0<<endl;
        } else if (k < r && r == p) {
            if (r == 2) cout<<2<<endl;
            else if (r == 3) {
                if (k == 1) cout<<1<<endl;
                else cout<<2<<endl;
            } else if (r == 4) {
                if (k == 2) cout<<0<<endl;
                else cout<<1<<endl;
            } else {
                cout<<0<<endl;
            }
        } else if (r == k && k == p) {
            if (k >= 5) cout<<0<<endl;
            else if (k == 1 || k == 4) cout<<2<<endl;
            else cout<<3<<endl;
        }
    }

    return 0;
}
