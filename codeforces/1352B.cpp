#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        if (n == 4) {
            cout<<2<<' '<<1<<' '<<3<<' '<<4<<endl;
            continue;
        }

        if (n&1) {
            for (int i= n-2; i >= 4; --i) {
                cout<<i<<' ';
            }
            cout<<1<<' '<<2<<' '<<3<<' ';
        } else {
            for (int i = n-2; i >=1 ; --i) cout<<i<<' ';
        }
        cout<<n-1<<' '<<n<<endl;
    }

    return 0;
}
