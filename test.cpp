#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    srand(time(NULL));
    int a = rand()^rand()^44497;
    int b = rand()^rand()^86243;
    (a&1)?(cout<<"*"<<'\n'):(cout<<"-"<<'\n');
    (b&1)?(cout<<"*"<<'\n'):(cout<<"-"<<'\n');
    return 0;
}
