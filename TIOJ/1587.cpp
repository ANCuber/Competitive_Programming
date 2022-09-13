#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string n; cin>>n;
    for (int i = 0; i < n.size(); ++i) {
        cout<<n[i];
    }
    for (int i = n.size()-2; i >= 0; --i) {
        cout<<n[i];
    }
    cout<<endl;
    return 0;
}
