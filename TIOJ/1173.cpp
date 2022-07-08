#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b, c;
    cin>>a>>b>>c;
    int ctrl = 0;
    if (c-b == b-a) ctrl++;
    if (b*b == a*c && a && b && c) ctrl+=2;
    if (!ctrl) {
        cout<<"normal";
    } else if (ctrl == 1) {
        cout<<"arithmetic";
    } else if (ctrl == 2) {
        cout<<"geometric";
    } else {
        cout<<"both";
    }
    cout<<endl;
    return 0;
}
