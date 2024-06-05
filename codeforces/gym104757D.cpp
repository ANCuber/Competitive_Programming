#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> A(10), L(10);
    int sum = 0;
    for (int i = 1; i <= 5; ++i) {
        int a, l; cin>>a>>l;
        sum += a*l;
    }
    //for (int i = 1; i <= 5; ++i) cin>>A[i];
    //for (int i = 1; i <= 5; ++i) cin>>L[i];
    //for (int i = 1; i <= 5; ++i) sum += A[i]*L[i];
    sum = sum/5;
    int N, K; cin>>N>>K;
    cout<<sum*N/K<<endl;
    return 0;
}
