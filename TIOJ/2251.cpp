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
    int n; cin>>n;    
    int a[n];
    for (int i = 0; i < n; ++i) cin>>a[i];
    sort(a,a+n);
    ll sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        ans += sum;
    }
    cout<<ans<<endl;
    return 0;
}
