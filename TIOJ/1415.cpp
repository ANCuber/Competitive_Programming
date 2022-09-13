#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n) {
        int k, a;
        ll ans = 0;
        p_q <int> mx, mxrm;
        p_q <int,vector<int>,greater<int> > mn, mnrm;
        while(n--) {
            cin>>k;
            while(k--) {
                cin>>a;
                mx.push(a);
                mn.push(a);
            }
            while(mxrm.size() && mx.top() == mxrm.top()) {
                mx.pop();
                mxrm.pop();
            }
            while(mnrm.size() && mn.top() == mnrm.top()) {
                mn.pop();
                mnrm.pop();
            }
            ans += (mx.top()-mn.top());
            mxrm.push(mn.top());
            mnrm.push(mx.top());
            mx.pop();
            mn.pop();
        }
        cout<<ans<<endl;
    }
    return 0;
}
