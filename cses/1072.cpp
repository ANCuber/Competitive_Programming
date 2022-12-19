#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

#define int ll

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    int cnt = 252;
    for (int i = 1; i <= n; ++i) {
        if (i == 1) cout<<0<<endl;
        else if (i == 2) cout<<6<<endl;
        else if (i == 3) cout<<28<<endl;
        else if (i == 4) cout<<96<<endl;
        else if (i == 5) cout<<252<<endl;
        else {
            cnt += (i-1)*(i-1)*(2*i-1)+2*(2+1+1+2)+2-4*(2*i-1)+(2*i-1)*(2*i-2)/2-2;
            cout<<cnt<<endl;
        }
    }
    return 0;
}
