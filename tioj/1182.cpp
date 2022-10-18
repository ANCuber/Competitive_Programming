#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    int n, m;
    while(t--) {
        cin>>n>>m;
        vector <int> a(n-1);
        for (int i = 0; i < n-1; ++i) {
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        for (int i = 0; i < n-2; ++i) {
            if (a[i] < m && a[i+1] > m) {
                cout<<a[i+1]<<' '<<a[i]<<endl;
                break;
            }
        }
    }
    return 0;
}
