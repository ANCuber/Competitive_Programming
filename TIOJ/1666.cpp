#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll a, b;
    while(cin>>a>>b) {
        if (!(a^b)) cout<<"yiping"<<endl;
        else cout<<"kelvin"<<endl;
    }
    return 0;
}
