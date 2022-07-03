#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>

struct KMF{
    string num;
    int val;
    int od;
    bool operator<(KMF b) {
        if (val == b.val) return od < b.od;
        return val < b.val;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; 
    while(cin>>n) {
        vector <KMF> a(n);
        for (int i = 0; i < n; ++i) {
            cin>>a[i].num;
            a[i].od = i;
            int v = 0;
            for (int j = 0; j < a[i].num.size(); ++j) {
                v += a[i].num[j]-'0';
            }
            a[i].val = v;
        }
        sort(a.begin(),a.end());
        for (int i = 0; i < n; ++i) {
            if (i) cout<<' ';
            cout<<a[i].num;
        }
        cout<<endl;
    }
    return 0;
}
