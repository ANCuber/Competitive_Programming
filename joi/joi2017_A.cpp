#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define pb push_back

struct BIT{
    vector<int> a;
    int sz;
    void init(int _n) {
        a.assign(_n+5,0);
        sz = _n;
    }
    void mdf(int p, int x) {
        while(p <= sz) {
            a[p] += x;
            p += p&-p;
        }
    }
    int val(int p) {
        int ans = 0;
        while(p) {
            ans += a[p];
            p -= p&-p;
        }
        return ans;
    }
} bit, ht;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q, s, t;
    cin>>n>>q>>s>>t;
    bit.init(n+1);
    ht.init(n+1);
    vector<int> a(n+2);
    for (int i = 0; i <= n; ++i) {
        cin>>a[i];
        if (i) {
            ht.mdf(i,a[i]-a[i-1]);
            if (a[i] > a[i-1]) {
                bit.mdf(i,(a[i-1]-a[i])*s);
                //cout<<"p1"<<endl;
            } else if (a[i] < a[i-1]) {
                bit.mdf(i,(a[i-1]-a[i])*t);
                //cout<<"p2"<<endl;
            }
        }
    }
    cout<<endl;
    while(q--) {
        int l, r, x; cin>>l>>r>>x;
        r++;
        if (x > 0) {
            if (ht.val(l) < ht.val(l-1)) {
                if (ht.val(l)+x > ht.val(l-1)) {
                    bit.mdf(l,(ht.val(l-1)-ht.val(l))*(-t)+(ht.val(l)+x-ht.val(l-1))*(-s));
                    //cout<<"p3"<<endl;
                } else {
                    bit.mdf(l,x*(-t));
                    //cout<<"p4"<<endl;
                }
            } else {
                bit.mdf(l,x*(-s));
                //cout<<"p5"<<endl;
            }
            x = -x;
            if (ht.val(r) > ht.val(r-1)) {
                if (ht.val(r)+x < ht.val(r-1)) {
                    bit.mdf(r,(ht.val(r)-ht.val(r-1))*s+(ht.val(r)+x-ht.val(r-1))*(-t));
                    //cout<<"p6"<<endl;
                } else {
                    bit.mdf(r,-x*s);
                    //cout<<"p7"<<endl;
                }
            } else {
                bit.mdf(r,-x*t);
                //cout<<"p8"<<endl;
            }
        } else if (x < 0) {
            if (ht.val(l) > ht.val(l-1)) {
                if (ht.val(l)+x < ht.val(l-1)) {
                    bit.mdf(l,(ht.val(l)-ht.val(l-1))*s+(ht.val(l)+x-ht.val(l-1))*(-t));
                    //cout<<"p9"<<endl;
                } else {
                    bit.mdf(l,-x*s);
                    //cout<<"p10"<<endl;
                }
            } else {
                bit.mdf(l,-x*t);
                //cout<<"p11"<<endl;
            }
            x = -x;
            if (ht.val(r) < ht.val(r-1)) {
                if (ht.val(r)+x > ht.val(r-1)) {
                    bit.mdf(r,(ht.val(r-1)-ht.val(r))*(-t)+(ht.val(r)+x-ht.val(r-1))*(-s));
                    //cout<<"p12"<<endl;
                } else {
                    bit.mdf(r,x*(-t));
                    //cout<<"p13"<<endl;
                }
            } else {
                bit.mdf(r,x*(-s));
                //cout<<"p14"<<endl;
            }
        }
        x = -x;
        ht.mdf(l,x), ht.mdf(r,-x);
        
        //for (int i = 0; i <= n; ++i) cout<<ht.val(i)<<' '; cout<<endl;
        //for (int i = 1; i <= n; ++i) cout<<bit.val(i)-bit.val(i-1)<<' '; cout<<endl;
        
        cout<<bit.val(n)<<'\n';
    }
    
    return 0;
}
