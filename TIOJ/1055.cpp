#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b; cin>>a>>b;
    if (a >= b) {
        for (int i = a; i >= b; --i) {
            for (int j = 0; j < i; ++j) cout<<'*';
            cout<<endl;
        }
    } else {
        for (int i = a; i <= b; ++i) {
            for (int j = 0; j < i; ++j) cout<<'*';
            cout<<endl;
        }
    }
    return 0;
}