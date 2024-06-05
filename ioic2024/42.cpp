#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin>>N>>M;
    int MX = 100;
    vector<int> u(1000005,0);
    for (int i = 1; i <= 1000; ++i) {
        u[i*i] = 1;
    }
    for (int i = 1; i <= MX; ++i) {
        for (int j = 1; j <= MX; ++j) {
            for (int k = 1; k <= MX; ++k) {
                for (int l = 1; l <= MX; ++l) {
                    int a = i*i*(N-1)+k*k, b = i*i*(M-1)+j*j, c = k*k*(M-1)+l*l, d = j*j*(N-1)+l*l;
                    if (u[a] && u[b] && u[c] && u[d]) {
                        for (int x = 1; x < N; ++x) {
                            for (int y = 1; y < M; ++y) {
                                cout<<i<<' ';
                            }
                            cout<<j<<endl;
                        }
                        for (int y = 1; y < M; ++y) cout<<k<<' ';
                        cout<<l<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
