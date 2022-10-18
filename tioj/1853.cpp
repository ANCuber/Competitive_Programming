#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

bitset <10000005> arr;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    string x; cin>>x;
    for (int i = 0; i < n; ++i) {
        arr[i] = x[i]-'0';
    }
}
