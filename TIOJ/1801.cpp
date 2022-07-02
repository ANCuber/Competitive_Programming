#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m; cin>>m;
    int n, k;
    for (int i = 1; i <= m; ++i) {
        cin>>n>>k;
        int cur = 0, p = 1;
        while(p <= n) {
            cur = (cur+k)%p;
            p++;
        }
        cout<<"Case "<<i<<": ";
        cout<<cur+1<<endl;
    }
    return 0;
}
