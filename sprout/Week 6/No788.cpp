#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int solve(int l, int r, vector <int> &arr) {

}

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector <int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        cout<<solve(0,n-1,arr)<<endl;
    }
    return 0;
}