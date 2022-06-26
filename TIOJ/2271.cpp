#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    int n; cin>>n;
    vector <long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    long long ans = 0;
    for (int i = 0; i < n>>1; ++i) {
        ans += arr[i];
    }
    cout<<ans<<endl;
    return 0;
}