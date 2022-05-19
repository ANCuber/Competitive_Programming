#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int n;

struct Dot{
    int x, y;
};

tuple<ll,ll,ll> coeff(int x1, int y1, int x2, int y2) {
    ll del = 1LL*x1*x2*(x1-x2);
    ll del_a;
    ll del_b;
}

int solve(vector <Dot> &p, vector <int> &dp,int cur, int counter) {
    if(dp[cur]) return dp[cur];
    
}

int main() {
    int t; cin>>t;
    while(t--) {
        cin>>n;
        if (n == 1) {
            cout<<1<<endl;
            continue;
        }
        vector <int> dp(1<<n,0);
        vector <Dot> pig(n);
        for (int i = 0; i < n; ++i) cin>>pig[i].x>>pig[i].y;
        cout<<solve(pig,dp,1<<n-1,0)<<endl;
    }
    return 0;
}

/*
2
7
1 3
2 4
3 3
2 6
4 8
1 1
1 2
6
1 8
2 12
3 12
4 4
5 5
6 6
*/