#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n) {
        if (cin.fail()) break;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        for (int i = 0; i < n; ++i) {
            if(i) cout<<' ';
            cout<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}