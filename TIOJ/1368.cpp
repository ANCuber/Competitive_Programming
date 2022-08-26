#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define int long long
#define p_q priority_queue
#define endl '\n'

int solve(int l, int r, vector<int> &arr) {
    
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n) {
        vector<int> arr(n+1);
        for (int i = 1; i <= n; ++i) cin>>arr[i];
        cout<<solve(1,n,arr)<<endl;
    }
    return 0;
}
