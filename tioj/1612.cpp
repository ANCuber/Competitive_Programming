#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'

int n, k;
ll x, d;

struct stage{
    ll x, v;
    bool operator<(stage b) {
        return x < b.x;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k>>x>>d;
    vector<stage> a(n+1,(0,0));
    vector<vector<ll> > dp(n,vector<ll>(k+1,0)); 
    for (int i = 1; i <= n; ++i) cin>>a[i].x>>a[i].v;
    sort(a.begin(),a.end());
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
             
        }
    }
    
    return 0;
}
