#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, T; cin>>N>>T;    
    vector<int> A(N+5);
    for (int i = 1; i <= N; ++i) {
        cin>>A[i];
        A[i] %= T;
        if ((-A[i]+T) < A[i]) A[i] -= T;
    }
    sort(A.begin()+1,A.begin()+N+1);
    int mid = (A[1]+A[N])/2;
    int ans = max(abs(A[1]-mid),abs(A[N]-mid));
    for (int i = 1; i < N; ++i) {
        int cur = A[i]+T;
        mid = (cur+A[i+1])/2;
        ans = min(ans,max(abs(A[i+1]-mid),abs(cur-mid)));
    }
    cout<<ans<<endl;
    return 0;
}
