#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int main() {
    int a, b;
    map <pii,int> mp;
    cin>>a>>b;
    mp[{a,b}] = 1;
    cout<<mp[{a,b}];
    return 0;
}
