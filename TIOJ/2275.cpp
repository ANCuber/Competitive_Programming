#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'
#define int ll 

int n, k;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    string s; cin>>s;
    vector<int> arr(n+1,0);
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    int ans = 0;
    deque < pair<int,int> > dq;
    dq.push_back({0,0});
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += (s[i-1]-'0');
        while(!dq.empty() && cnt-dq.front().second > k) {
            dq.pop_front();
        }
        ans = max(ans,arr[i]-dq.front().first);
        while(!dq.empty() && dq.back().first > arr[i]) {
            dq.pop_back();
        }
        dq.push_back({arr[i],cnt});
    }
    cout<<ans<<endl;

    return 0;
}
