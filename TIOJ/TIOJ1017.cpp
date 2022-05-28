#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        stack <int,vector<int> > stk;
        for (int i = 0; i < n; ++i) {
            int a; cin>>a;
            if (stk.empty()) {
                stk.push(a);
            } else {
                if (a > stk.top()) {
                    stk.push(a);
                }
            }
        }
        cout<<stk.size()-2<<endl;
    }
    return 0;
}