#include <bits/stdc++.h>
using namespace std;

const int N = 6;

struct Matrix{
    long long a[N][N];
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

int main() {
    Matrix a;
    int n; cin>>n;
    a.init(n);
    for (int i = 0; i < a.n; ++i) {
        for (int j = 0; j < a.n; ++j) {
            cout<<a.a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}