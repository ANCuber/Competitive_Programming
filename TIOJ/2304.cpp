#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector <int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int minn = arr[0];
    bool ctrl = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[0]+i) break;
        if (i == n-1) ctrl = 1;
    }
    if (ctrl) cout<<minn<<' '<<arr[n-1]<<' '<<"yes\n";
    else cout<<minn<<' '<<arr[n-1]<<' '<<"no\n";
    return 0;
}
