#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#define ull unsigned long long
#pragma GCC optimize("Ofast")

const ull mod = 1e9+7;
const int N = 6;

struct Matrix{
    ull a[N][N];
    int sz;
    void init(int n) {
        sz = n;
        memset(a,0,sizeof(a));
    }
    void I() {
        memset(a,0,sizeof(a));
        for (int i = 0; i < N; ++i) a[i][i] = 1;
    }
};

Matrix operator*(const Matrix &x, const Matrix &y) {
    Matrix ans;
    ans.init(x.sz);
    int size = x.sz;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                ans.a[i][j] += (x.a[i][k]*y.a[k][j])%mod;
            }
        }
    }
    return ans;
}

Matrix operator^(const Matrix &x, ull y) {
    Matrix ans, now = x;
    ans.init(x.sz);
    ans.I();
    while(y) {
        if (y&1) ans = ans*now;
        now = now*now;
        y >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ull x1, x2, a, b, n;
    cin>>x1>>x2>>a>>b>>n;
    n -= 2;
    Matrix ans, f;
    f.init(2);
    f.a[0][0] = b;
    f.a[0][1] = a;
    f.a[1][0] = 1;
    f.a[1][1] = 0;
    ans = f^n;
    cout<<((ans.a[0][0]*x2)%mod+(ans.a[0][1]*x1)%mod)%mod<<endl;

    return 0;
}
