#include <bits/stdc++.h>
using namespace std;

int solve (vector <int> &arr,int l,int r) {
    if (l == r) return arr[l];
    int mid = (l+r)/2;
    int out_ans = max(solve(arr,l,mid),solve(arr,mid+1,r));
    int lmax = arr[mid];
    int ltemp = arr[mid];
    for (int i = mid-1; i >= l; --i) {
        ltemp += arr[i];
        lmax = max(lmax, ltemp);
    }
    int rmax = arr[mid+1];
    int rtemp = arr[mid+1];
    for (int i = mid+2; i <= r; ++i) {
        rtemp += arr[i];
        rmax = max(rmax, rtemp);
    }
    return max(out_ans, lmax+rmax);
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector <int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        cout<<solve(arr,0,n-1)<<'\n';
    }
    return 0;
}