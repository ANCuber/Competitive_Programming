#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    while(cin>>n>>k) {
        vector <string> arr(n);
        for (int i = 0; i < n; ++i) cin>>arr[i];
        cout<<arr[n-k]<<endl;
    }
    return 0;
}