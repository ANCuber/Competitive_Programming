#pragma GCC optimize("O3,unroll-loops")
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
    int n, a, sum; cin>>n>>a;
    vector<int> dp(n+1,0);
    dp[a] = sum = 1;
    for (int i = 2; i <= n; ++i) {
        cin>>a;
        
    }
    return 0;
}
