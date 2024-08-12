#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void MergeSort(vector<int> &a, int L, int R) {
    if (L == R) return;
    int M = (L+R)/2;
    MergeSort(a,L,M), MergeSort(a,M+1,R);
    int pl = L, pr = M+1;
    vector<int> tmp;
    while(pl <= M && pr <= R) {
        if (a[pl] <= a[pr]) tmp.push_back(a[pl++]);
        else tmp.push_back(a[pr++]);
    }
    while(pl <= M) tmp.push_back(a[pl++]);
    while(pr <= R) tmp.push_back(a[pr++]);
    for (int i = L; i <= R; ++i) a[i] = tmp[i-L];
}

void Solve(int n) {
    vector<int> a(n+5);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    MergeSort(a,1,n);
    for (int i = 1; i <= n; ++i) {
        if (i-1) cout<<' ';
        cout<<a[i];
    }
    cout<<'\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while(cin>>n) Solve(n);
    return 0;
}
