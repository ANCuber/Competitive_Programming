#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int mod = 1e9+7;
const int N = 100;

struct Matrix{
    ll a[N][N];
    int n;
    void init(int size) {
        n = size;
        memset(a,0,sizeof(a));
    }
    void I() {
        memset(a,0,sizeof(a));
        for (int i = 0; i < n; ++i) {
            a[i][i] = 1;
        }
    }
};

Matrix operator*(const Matrix &m1, const Matrix &m2) {
    Matrix ans;
    ans.init(m1.n);
    int size = m1.n;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                ans.a[i][j] += (m1.a[i][k]%mod)*(m2.a[k][j]%mod);
                ans.a[i][j] %= mod;
            }
        }
    }
    return ans;
}

Matrix power(Matrix a, ll n) {
    Matrix ans, now = a;
    ans.init(a.n);
    ans.I();
    while(n) {
        if(n&1) ans = ans*now;
        now = now*now;
        n>>=1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, l;
    cin>>n>>m>>l;
    Matrix graph;
    graph.init(n);
    for (int i = 0; i < m; ++i) {
        int x, y; cin>>x>>y;
        x--, y--;//0 base
        graph.a[x][y] = 1;
    }
    Matrix ans = power(graph,l);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j) cout<<' ';
            cout<<ans.a[i][j]%mod;
        }
        cout<<endl;
    }
    return 0;
}