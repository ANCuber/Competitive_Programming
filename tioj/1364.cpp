#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    while(cin>>n>>k) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        sort(a.begin(),a.end(),greater<int>());
        cout<<a[k-1]<<endl;
    }
    return 0;
}
