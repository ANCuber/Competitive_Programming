#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;
    int r, c;
    vector<vector<int> > gr(n+1);
    vector<vector<int> > gc(n+1);
    vector<int> rsz(n+1,0);
    vector<int> csz(n+1,0);
    while(k--) {
        cin>>r>>c;
        gr[r].push_back(c);
        rsz[r]++;
        gc[c].push_back(r);
        csz[c]++;
    }
    int ctrl = 0;
    int maxi = 0, maxn = 0;
    for (int i = 1; i <= n; ++i) {
        if (rsz[i] > maxn) {
            ctrl = 0;
            maxi = i;
            maxn = rsz[i];
        }
        if (csz[i] > maxn) {
            ctrl = 1;
            maxi = i;
            maxn = csz[i];
        }
    }
}
