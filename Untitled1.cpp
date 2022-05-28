#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

int main() {
    int n; cin>>n;
    multiset <int> lis;
    for (int i = 0; i < n; ++i) {
        int a; cin>>a;
        lis.insert(a);
        auto iter = lis.upper_bound(a);
        if (iter != lis.end()) lis.erase(iter);
    }
    cout<< lis.size() << endl;
    return 0;
}