#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

vector<int> a;
int n, t;
int k;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--) {
        cin>>n;
        k = 0;
        a.assign(n+1,0);
        for (int i = 1; i <= n; ++i) cin>>a[i];
    }
    return 0;
}
