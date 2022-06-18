#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<int> a;
vector<int> prexor;

int main() {
    int n, k; cin>>n>>k;
    a.resize(n+1);
    prexor.resize(n+1,0);
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        prexor[i] = prexor[i-1]^a[i];
    }

}