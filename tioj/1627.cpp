#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'

int n, t, q;
const int maxT = 5e6;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n>>t>>q) {
        vector<int> tmp(maxT+5,0), ans(maxT+5,0); 
        int x;
        while(n--) {
            cin>>x;
            tmp[x]++;
        }
        for (int i = 0; i <= maxT; ++i) {
            if (!tmp[i]) continue;
            for (int j = 0, cnt = 0; j <= maxT; j += i, cnt++) {
                if (cnt&1) ans[j] -= tmp[i];
                else ans[j] += tmp[i];
            }
        }
        for (int i = 1; i <= maxT; ++i) {
            ans[i] += ans[i-1];
        }
    
        while(q--) {
            cin>>x;
            cout<<ans[x]<<endl;
        }
        cout<<endl;
    }

    return 0;
}
