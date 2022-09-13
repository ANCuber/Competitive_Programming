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
    int n, k; cin>>n>>k;    
    vector<vector<int> > a(n,vector<int>(n));
    vector< pii > org(n);
    for (int i = 0; i < n; ++i) {
        cin>>org[i].first;
        org[i].second = i;
    }
    sort(org.begin(),org.end());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>a[i][j];
        }
    }
    

    return 0;
}
