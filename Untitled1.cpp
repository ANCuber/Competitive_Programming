#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y,x%y);
}

int main() {
    int a, b; cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}
