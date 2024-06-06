#include <iostream>
#include <vector>
using namespace std;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin>>n;
    vector<int> a(n);
    for (auto &i : a) cin>>i;
    cout<<a.back()<<endl;
    return 0;
}
