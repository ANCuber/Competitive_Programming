#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        multiset <int> arr;
        for (int i = 0; i < n; ++i) {
            int a; cin>>a;
            if (a*2 >= m) {
                arr.insert(a*2);
                auto iter = arr.upper_bound(a*2);
                if (iter != arr.end()) arr.erase(iter);
            }
            if (a >= m) {
                arr.insert(a);
                auto iter = arr.upper_bound(a);
                if (iter != arr.end()) arr.erase(iter);
            }
        }
        cout<<arr.size()<<endl;
    }
    return 0;
}