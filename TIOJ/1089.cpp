#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

struct Arr{
    int dir;
    int id;
    int val;
    bool operator<(Arr b) {
        return val < b.val;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;
    int r, c;
    vector<vector<int> > g(n+1);
    while(k--) {
        cin>>r>>c;
        g[r].push_back(c);
    }
}
