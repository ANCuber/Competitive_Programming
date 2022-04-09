#include <bits/stdc++.h>
using namespace std;

const long long mod = 10000019;

long long ans = 0;

void solve(vector <int> &arr, int l, int r) {
    if (l==r) return;
    if (r-1 == 1) {
        if (l > r) ans += (long long)(arr[l]%mod + arr[r]%mod);
        return;
    }
    int mid = l+(r-l)/2;
    vector <int> arr1(mid+1);
    vector <int> arr2(r-l-mid);
    for (int i = l; i < mid+1; ++i) {
        arr1[i] = arr[i];
    }
    for (auto i : arr1) cout<<i<<' ';
    cout<<'\n';
    for (int i = mid+1; i <= r; ++i) {
        arr2[i] = arr[i];
    }
    for (auto i : arr2) cout<<i<<' ';
    cout<<'\n';
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    for (int i = 0; i <= mid; ++i) {
        int index = mid;
        while(arr1[i] > arr2[++index]) {
            ans += (long long)(arr1[i]%mod + arr2[index]%mod);
        }
    }
    solve(arr,l,mid);
    solve(arr,mid+1,r);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout<<"pass";
    int n; cin>>n;
    vector <int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    solve(arr,0,n-1);
    cout<<ans<<'\n';
    return 0;
}