#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n; cin>>n;    
    if (n*(n+1)%4) {
        cout<<"NO\n";
    } else {
        cout<<"YES\n";
        if (n&1) {
            set<int> f, s;
            f.insert(1), f.insert((n+1)/2);
            for (int i = 2; i <= (n+1)/4; ++i) {
                f.insert(i);
                f.insert(n-i+2);
            }
            s.insert((n+1)/2+1);
            for (int i = (n+1)/4+1; i < (n+1)/2; ++i) {
                s.insert(i);
                s.insert(n-i+2);
            }
            cout<<f.size()<<endl;
            int fg = 0;
            for (auto i : f) {
                if (fg) cout<<' ';
                cout<<i;
                fg = 1;
            }
            fg = 0;
            cout<<endl<<s.size()<<endl;
            for (auto i : s) {
                if (fg) cout<<' ';
                cout<<i;
                fg = 1;
            }
        } else {
            set<int> f, s;
            for (int i = 1; i <= n/4; ++i) {
                f.insert(i);
                f.insert(n-i+1);
            }
            for (int i = n/4+1; i <= n/2; ++i) {
                s.insert(i);
                s.insert(n-i+1);
            }
            cout<<f.size()<<endl;
            int fg = 0;
            for (auto i : f) {
                if (fg) cout<<' ';
                cout<<i;
                fg = 1;
            }
            fg = 0;
            cout<<endl<<s.size()<<endl;
            for (auto i : s) {
                if (fg) cout<<' ';
                cout<<i;
                fg = 1;
            }

        }
    }
    return 0;
}
