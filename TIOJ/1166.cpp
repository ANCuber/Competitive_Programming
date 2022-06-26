#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y,x%y);
}

int main() {
    int a, b;
    while(cin>>a>>b) {
        if (!a && !b) break;
        cout<<__gcd(a,b)<<endl;
    }
    return 0;
}