#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    string p, q;
    cin>>p>>q;
    int ctrl = 1;
    int ans = 0;
    while(ctrl <= min(p.size(),q.size())) {
        int bl = 0;
        for (int k = 0; k < ctrl; ++k) {
            if (p[k] != q[q.size()-ctrl+k]) {
                bl = 1;
                break;
            }
        }
        if (!bl) ans = ctrl;
        ctrl++;
    }
    cout<<ans<<endl;
    return 0;
}