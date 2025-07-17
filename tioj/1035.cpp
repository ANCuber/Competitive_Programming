#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const double eps = 1e-6, PI = acos(-1.0);

void FFT(vector<complex<double> > &a, int n, int inv) {
    if (n <= 1) return;
    int k = __lg(n);

    vector<int> rev(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j)
            rev[i] = (rev[i] << 1) | ((i >> j) & 1);

    for (int i = 0; i < n; ++i)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);

    vector<complex<double> > w(n);
    for (int i = 0; i < n; ++i) 
        w[i] = polar(1.0, inv * 2 * PI * i / n);

    for (int i = 1, len = 2; i <= k; ++i, len <<= 1) {
        for (int j = 0; j < n; j += len) {
            for (int p = 0; p < (len >> 1); ++p) {
                complex<double> u = a[j + p], v = a[j + p + (len >> 1)];
                a[j + p] = u + w[p * (n / len)] * v;
                a[j + p + (len >> 1)] = u - w[p * (n / len)] * v;
            }
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size(), len = 1;
    while (len < n + m - 1) len <<= 1;

    vector<int> ans(len, 0);
    for (int i = 0; i < 10; ++i) {
        vector<complex<double> > F(len), G(len);
        char cur = (char)('a' + i);
        for (int j = 0; j < n; ++j) 
            F[j].real(s[j] == cur ? 1 : 0);
        for (int j = 0; j < m; ++j)
            G[m - j - 1].real(t[j] == cur ? 1 : 0);
        FFT(F, len, 1);
        FFT(G, len, 1);
        for (int j = 0; j < len; ++j) F[j] *= G[j];
        FFT(F, len, -1);
        for (int j = 0; j < len; ++j) 
            ans[j] += round(F[j].real() / len);
    }
    cout << *max_element(ans.begin(), ans.end()) << "\n";
    return 0;
}
