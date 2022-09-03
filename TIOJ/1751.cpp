#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    vector<ll> fn(50);
    fn[0] = 1, fn[1] = 2;
    int cnt;
    for (int i = 2;i <= 45;++i) {
        fn[i] = fn[i-1]+fn[i-2];
    }
    ll k;
    while(t--) {
        cin>>k;
        int ans = 0;
        if (k<0) {
            cout<<"iyada~"<<endl;
            continue;
        }
        while(k) {
            auto iter = upper_bound(fn.begin(),fn.begin()+45,k);
            iter--;
            k -= *iter;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
