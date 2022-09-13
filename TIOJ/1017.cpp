#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int arr[n];
        for (int i = 0; i < n; ++i) cin>>arr[i];
        int lmax[n], rmin[n];
        lmax[0] = arr[0];
        rmin[n-1] = arr[n-1];
        for (int i = 1; i < n; ++i) {
            lmax[i] = max(lmax[i-1],arr[i]);
        }
        for (int i = n-2; i >= 0; --i) {
            rmin[i] = min(rmin[i+1],arr[i]);
        }
        int ans = 0;
        for (int i = 1; i < n-1; ++i) {
            if (lmax[i-1] < arr[i] && arr[i] < rmin[i+1]) {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
