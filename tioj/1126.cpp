#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string x;
    while(cin>>x) {
        int len = x.size();
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            int j = 0;
            for (; i-j >= 0 && i+j < len; ++j) {
                if (x[i-j] != x[i+j]) break;
            }
            ans = max(ans,2*j-1);
            for (j = 0; i-j >= 0 && i+j+1 < len; ++j) {
                if (x[i-j] != x[i+j+1]) break;
            }
            ans = max(ans,2*j);
        }
        cout<<ans<<endl;
    }
    return 0;
}
