#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int long long

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a;
    while(cin>>a) {
        if (a == 0) {
            cout<<100<<endl;
            continue;
        }
        int cnt = 0, ans = 10;
        vector<int> dp((1<<15)+1,0);
        dp[++cnt] = a;
        while(cin>>a) {
            cnt++;
            ans += 10;
            if (cnt <= 3) dp[cnt] = a;
            else dp[cnt] = a+min({dp[cnt-1],dp[cnt-2],dp[cnt-3]});
            if (!a) break;
        }
        cout<<(ans+dp[cnt])*10<<endl;
    }
    return 0;
}
