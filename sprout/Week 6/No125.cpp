#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mod 10000019

int n;
long long ans = 0;

void solve(vector <long long> &arr, int l, int r) {
    if (l == r) return;
    int mid = (l+r)/2;
    solve(arr,l,mid);
    solve(arr,mid+1,r);
    int index = mid+1;
    long long presum = 0;
    for (int i = l; i <= mid; ++i) {
        while (index <= r && arr[i] > arr[index]) {
            presum += arr[index++];
        }
        //ans += presum%mod;
        ans += (arr[i]*(index-mid-1) + presum);
        ans %= mod;
    } 
    int temp[r-l+1];
    int len = 0;
    int p1 = l, p2 = mid+1;
    while(len < r-l+1) {
        if (p1 <= mid && p2 <= r) {
            if (arr[p1] < arr[p2]) {
                temp[len++] = arr[p1++];
            } else {
                temp[len++] = arr[p2++];
            }
        } else {
            if (p1 == mid+1) {
                temp[len++] = arr[p2++];
            } else {
                temp[len++] = arr[p1++];
            }
        }
    }
    int id = 0;
    for (int i = l; i <= r; ++i) {
        arr[i] = temp[id++];
    }
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    vector <long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    solve(arr,0,n-1);
    //for (auto i : arr) cout<<i<<' ';
    //cout<<endl;
    cout<<ans<<endl;
    return 0;
} 