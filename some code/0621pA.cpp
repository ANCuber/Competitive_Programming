#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    int l = 1, r = n;
    for (int i = 1; i <= n; i+=4) {
        cout<<"? "<<4<<' '<<i<<' '<<i+1<<' '<<i+2<<' '<<i+3<<endl;
    }
}