#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    int n, m, k;
    cin>>n>>m>>k;
    vector <vector<int> > a(n,vector<int>(m));
    vector <vector<int> > b(m,vector<int>(k));
    vector <vector<int> > c(n,vector<int>(k));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin>>a[i][j];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) cin>>b[i][j];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) cin>>c[i][j];
    }
}