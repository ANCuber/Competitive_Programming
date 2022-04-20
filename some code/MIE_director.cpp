#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, p;
    cin>>x>>y>>p;
    if (((x%p)*(y%p))%p == 1) cout<<"Accepted.\n";
    else cout<<"Fail.\n";
    return 0;
}