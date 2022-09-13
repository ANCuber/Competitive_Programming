#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

int n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n) {
        p_q <int,vector<int>,greater<int> > pq;
        int a;
        for (int i = 0; i < n; ++i) {
            cin>>a;
            pq.push(a);
        }
        ll ans = 0;
        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            pq.push(x+y);
            ans += (x+y);
        }
        cout<<ans<<endl;
    }
    return 0;
}
