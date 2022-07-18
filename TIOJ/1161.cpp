#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    int n, k;
    while(t--) {
        cin>>n>>k;
        vector < pii > sk(n);
        p_q <int> pq;
        for (int i = 0; i < n; ++i) {
            cin>>sk[i].first>>sk[i].second;
        }
        sort(sk.begin(),sk.end());
        for (int i = 0; i < k; ++i) {
            pq.push(sk[i].second);
        }
        int ans = sk[k-1].first+pq.top();
        for (int i = k; i < n; ++i) {
            pq.push(sk[i].second);
            pq.pop();
            ans = min(ans,sk[i].first+pq.top());
        }
        cout<<ans<<endl;
    }
    return 0;
}
