#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    ll fb[31];
    int alp[3] = {1,2,0};
    fb[0] = 1, fb[1] = 1;
    for (int i = 2; i < 31; ++i) fb[i] = fb[i-1]+fb[i-2];
    int ctrl = 0;
    for (int i = 1; i <= t; ++i) {
        for (int j = 0; j < fb[i]; ++j) {
            cout<<alp[ctrl];
            ctrl = (ctrl+1)%3;
        }
        cout<<endl;
    }
    return 0;
}