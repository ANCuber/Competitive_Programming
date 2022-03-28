#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    stack <int> stk;
    for (int i = 1; i <= t; i++) {
        int x; cin>>x;
        if (x == 1) {
            int n; cin>>n;
            stk.push(n);
        } else {
            if (stk.empty()) cout<<"empty!\n";
            else {
                cout<<stk.top()<<'\n';
                stk.pop();
            }
        }
    }
    return 0;
} 