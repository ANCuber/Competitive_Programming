#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n) {
        ll arr[n];
        for (int i = 0; i < n; ++i) cin>>arr[i];
        sort(arr,arr+n);
        for (int i = 0; i < n; ++i) {
            if (i) cout<<' ';
            cout<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}
