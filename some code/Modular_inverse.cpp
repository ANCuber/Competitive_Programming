#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

//ax + py = 1, x is the modular inverse of a under the model of p
int exgcd(int a, int p, int am, int an, int pm, int pn) {
    if (p == 0) return am;
    return exgcd(p,a%p,pm,pn,am-(pm*(a/p)),an-(pn*(a/p)));
}

int main() {
    int a, p;
    cin>>a>>p;
    int mie = exgcd(a,p,1,0,0,1);
    if (mie > 0) cout<<mie<<endl;
    else cout<<mie+p<<endl;
    return 0;
}