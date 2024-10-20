#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int ctrl = 0;

auto seed = std::chrono::steady_clock::now().time_since_epoch().count();

std::mt19937 gen(seed);

std::uniform_int_distribution<int> unif(1, (int)1e7);

inline int next() {
    return unif(gen);
}

void solve(int n, int m, int k) {
    vector <vector<ll> > a(n,vector<ll>(m));
    vector <vector<ll> > b(m,vector<ll>(k));
    vector <vector<ll> > c(n,vector<ll>(k));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin>>a[i][j];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) cin>>b[i][j];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) cin>>c[i][j];
    }
    for (int i = 0; i < 1; ++i) {
        vector <ll> R(k);
        for (int i = 0; i < k; ++i) R[i] = next();
        vector <ll> nb(m,0);
        vector <ll> nc(n,0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < k; ++j) nb[i] += R[j]*b[i][j];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) nc[i] += R[j]*c[i][j];
        }
        vector <ll> dir(n,0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) dir[i] += nb[j]*a[i][j];
        }
        for (int i = 0; i < n; ++i) {
            if (dir[i] != nc[i]) ctrl = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin>>n>>m>>k;
    solve(n,m,k);
    if (ctrl) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}