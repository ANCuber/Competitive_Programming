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
    int n;
    ll sum = 0;
    int cnt = 0;
    while(true) {
        cin>>n;
        if (!cnt && !n) break;
        if (!n) {
            cout<<cnt<<' '<<sum<<endl;
            sum = 0;
            cnt = 0;
            continue;
        }
        if(!cnt) cout<<n<<' ';
        cnt++;
        sum += n;
    }
    return 0;
}
