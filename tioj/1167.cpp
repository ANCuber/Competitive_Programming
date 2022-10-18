#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    while(cin>>n>>k && n && k) {
        vector<int> a(n);
        for (auto& i : a) cin>>i;
        sort(a.begin(),a.end(),greater<int>());
        cout<<a[--k]<<endl;
    }
    return 0;
}
