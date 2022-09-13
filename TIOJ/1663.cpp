#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, a, b;
    while(cin>>t>>a>>b) {
        if (t == 1) {
            cout<<a+b<<endl;
        } else if (t == 2) {
            cout<<a-b<<endl;
        } else if (t == 3) {
            cout<<a*b<<endl;
        } else {
            cout<<a%b<<endl;
        }
    }
    return 0;
}
