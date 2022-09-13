#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    cout<<2*n+n+1<<endl;
    for (int i = 0; i < n; ++i) {
        cout<<i<<' '<<i<<' ';
    }
    cout<<0;
    for (int i = n-1; i >= 0;--i) {
        cout<<' '<<i;
    }
    cout<<endl;
    return 0;
}
