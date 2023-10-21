#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int unsigned __int128
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int A, B, M;

struct Matrix{
    //vector<vector<int> > a(3,vector<int>(3,0));
    int a[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    void I() {
        for (int i = 1; i <= 2; ++i) for (int j = 1; j <= 2; ++j) a[i][j] = 0;
        a[1][1] = a[2][2] = 1;
    }
} mat;

Matrix MUL(Matrix &x, Matrix &y) {
    Matrix ret;
    for (int i = 1; i <= 2; ++i) {
        for (int j = 1; j <= 2; ++j) {
            for (int k = 1; k <= 2; ++k) {
                ret.a[i][j] = (ret.a[i][j]+(x.a[i][k])*(y.a[k][j])%M)%M;
            }
        }
    }
    return ret;
}

Matrix power(Matrix &a, int k) {
    Matrix ret, bs;
    ret.I(), bs = a;
    while(k) {
        if (k&1) ret = MUL(ret,bs);
        bs = MUL(bs,bs);
        k >>= 1;
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    unsigned long long I, J, K;
    cin>>I>>J>>K;
    A = I, B = J, M = K;
    Matrix Tra;
    Tra.a[1][1] = A%M, Tra.a[1][2] = -1+M, Tra.a[2][1] = 1, Tra.a[2][2] = 0;
    Tra = power(Tra,B-1);
    cout<<(unsigned long long)((A%M*(Tra.a[1][1])+2*(Tra.a[1][2]))%M)<<endl;
    return 0;
}
