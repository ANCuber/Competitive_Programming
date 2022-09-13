#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define eb emplace_back

ll solve(int l, int r, vector<int> &arr) {
    if (l == r) return 0;
    if (r-l == 1) {
        if (arr[r]>=arr[l]) return 0;
        else {
            swap(arr[r],arr[l]);
            return 1;
        }
    }
    ll ret = 0;
    int mid = (l+r)>>1;
    ret += solve(l,mid,arr);
    ret += solve(mid+1,r,arr);
    int p1 = l, p2 = mid+1;
    vector<int> temp;
    while(p1 <= mid && p2 <= r) {
        if (arr[p1] <= arr[p2]) {
            temp.eb(arr[p1++]);
        } else {
            temp.eb(arr[p2++]);
            ret += (mid-p1+1);
        }
    }
    while(p1 <= mid) {
        temp.eb(arr[p1++]);
    }
    while(p2 <= r) {
        temp.eb(arr[p2++]);
    }
    for (int i = 0; i < temp.size(); ++i) {
        arr[i+l] = temp[i];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int number = 1;
    int n;
    while(true) {
        cin>>n;
        if (!n) break;
        vector <int> arr(n+1);
        for (int i = 1; i <= n; ++i) {
            cin>>arr[i];
        }
        cout<<"Case #"<<number++<<": ";
        cout<<solve(1,n,arr)<<endl;
    }
    return 0;
}