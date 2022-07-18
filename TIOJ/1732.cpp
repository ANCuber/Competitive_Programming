#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n) {
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin>>p[i];
        }
        sort(p.begin(),p.end());
        int mid;
        if (n % 2 == 1) {
            mid = p[(n/2)];
        } else {
            mid = (p[n/2-1]+p[(n/2)])>>1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += abs(mid-p[i]);
        }
        //cout<<mid<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
