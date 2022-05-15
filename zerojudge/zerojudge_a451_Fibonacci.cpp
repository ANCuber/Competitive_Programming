#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
long long mod;
const int N = 6;

struct Matrix{
    long long a[N][N];
    int n;
    void init(int _n) {
        n = _n;
        memset(a,0,sizeof(a));
    }
    void I() {
        memset(a,0,sizeof(a));
        for (int i = 0; i < N; ++i) {
            a[i][i] = 1;
        }
    }
};

Matrix operator* (const Matrix &m1, const Matrix &m2) {
    Matrix ans;
    ans.init(m1.n);
    int size = m1.n;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                ans.a[i][j] += (m1.a[i][k] % mod)*(m2.a[k][j] % mod);
                ans.a[i][j] %= mod;
            }
        }
    }
    return ans;
}

Matrix power(Matrix a, long long n) {
    Matrix ans, now = a;
    ans.init(2);
    ans.I();
    while(n){
        if (n&1) ans = ans*now;
        now = now*now;
        n>>=1;
    }
    return ans;
}

int main() {
    long long n;
    while(cin>>n>>mod) {
        mod = 1<<mod;
        if (!n) {
            cout<<0%mod<<endl;
            continue;
        }
        if (n == 1 || n == 2) {
            cout<<1%mod<<endl;
            continue;
        }
        n -= 2;
        Matrix mat;
        mat.init(2);
        mat.a[0][0] = 1;
        mat.a[0][1] = 1;
        mat.a[1][0] = 1;
        mat.a[1][1] = 0;
        Matrix ans = power(mat,n);
        cout<<(ans.a[0][0]+ans.a[0][1])%mod<<endl;        
    }
    return 0;
}