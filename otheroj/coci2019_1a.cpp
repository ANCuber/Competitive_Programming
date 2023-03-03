#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int sum[15] = {0,1,3,6,10,15,21,28,36,45};

signed main() {
    int q; cin>>q; 
    while(q--) {
        int l, r; cin>>l>>r;
        int k = l, cnt = 0, ans = 0;
        while(k) {
            cnt += k%10;
            k /= 10;
            if (!k && cnt > 10) {
                k = cnt;
                cnt = 0;
            }
        }
        while(cnt < 10 && l <= r) {
            ans += cnt;
            l++, cnt++;
        }
        if (r >= l) {
            ans += (r-l+1)/9*45;
            int tmp = r-l+1-(r-l+1)/9*9;
            ans += sum[tmp];
        }
        cout<<ans<<endl;
    }
    return 0;
}
