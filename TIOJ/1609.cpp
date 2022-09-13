#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector <int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for (auto i : arr) {
        cout<<i<<' ';
    }
    cout<<endl;
    return 0;
}