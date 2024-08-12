#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool cmpr(vector<ll> &h, vector<ll> w, ll g) {
    int j = 0;
    int sw = w[0];
    for (int i = 0; i < h.size() && j < w.size(); ++i) {
        if (h[i] < g) {
            w[j] = sw;
            continue;
        }
        w[j]--;
        if (!w[j]) {
            sw = w[++j];
        }
    }
    if (j == w.size()) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;
    vector <ll> h(n);
    vector <ll> w(k);
    for (int i = 0; i < n; ++i) cin>>h[i];
    for (int i = 0; i < k; ++i) cin>>w[i];
    ll b = 0;
    ll t = (1e9)+1;
    ll guess = b+(t-b)/2;
    while(t-b > 1) {
        if (cmpr(h,w,guess)) {
            b = guess;
        } else {
            t = guess;
        }
        guess = b+(t-b)/2;
    }
    cout<<b<<endl;
    return 0;
}
