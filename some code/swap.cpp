#include <bits/stdc++.h>
using namespace std;

void myswap(int *a, int *b) {
    int an = *a;
    int bn = *b;
    *a = bn;
    *b = an;
}

int main() {
    int a, b; cin>>a>>b;
    cout<<"a="<<a<<' '<<"b="<<b<<'\n';
    myswap(&a,&b);
    cout<<"a="<<a<<' '<<"b="<<b<<'\n';
    return 0;
}