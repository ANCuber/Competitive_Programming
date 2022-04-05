#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int, greater<int> > v{5,4,2,1,3};
    sort(v.begin(),v.end());
    for(auto i : v) cout<<i<<' ';
    return 0;
}