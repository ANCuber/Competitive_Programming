#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    int p, q;
    cin>>p>>q;
    if (p%q == 0 || q%p == 0) cout<<'Y'<<endl;
    else cout<<'N'<<endl;
    return 0;
}