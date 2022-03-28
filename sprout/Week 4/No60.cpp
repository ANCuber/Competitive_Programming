#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
int m, s, t;

int main() {
    cin>>a>>b>>c>>d;
    cin>>m>>s>>t;
    int t0 = m/c;
    m %= c;
    s -= t0*b;
    t -= t0;
    
}