#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll a, b, c;
    while(cin>>a>>b>>c) {
        if (max({a,b,c}) < a+b+c-max({a,b,c})) cout<<"SAFE"<<endl;
        else cout<<"BYE"<<endl;
    }
    return 0;
}
