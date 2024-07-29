#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin>>arr[i];
    sort(arr.begin(),arr.begin()+n);
    int q; cin>>q;
    while(q--) {
        int k; cin>>k;
        auto iter = lower_bound(arr.begin(),arr.end(),k);//<
        iter--;
        cout<<*iter<<endl;
        iter = upper_bound(arr.begin(),arr.end(),k);//<= 
        iter--;
        cout<<*iter<<endl;

        int L = -1, R = n;
        while(R-L > 1) {//>=
            int M = (L+R)/2;
            if (arr[M] >= k) R = M;
            else L = M;
        }
        cout<<arr[R]<<endl;
    }
}
