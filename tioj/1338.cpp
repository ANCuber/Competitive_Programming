#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include "lib1338.h"
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

vector<vector<ll> > MIN, GCD;

void init(int n, long long C[]) {
    MIN.assign(__lg(n)+1,vector<ll>(n+5,1e9));
    GCD.assign(__lg(n)+1,vector<ll>(n+5));
    for (int j = 0; j < n; ++j) {
        GCD[0][j] = C[j];
        MIN[0][j] = C[j];
    }
    for (int i = 1; i <= __lg(n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (j+(1<<(i-1)) >= n) continue;
            GCD[i][j] = __gcd(GCD[i-1][j],GCD[i-1][j+(1<<(i-1))]);
            MIN[i][j] = min(MIN[i-1][j],MIN[i-1][j+(1<<(i-1))]);
        }
    }
}

int query(int L, int R) {
    R--;
    int LG = __lg(R-L+1);
    int CG = __gcd(GCD[LG][L],GCD[LG][R-(1<<LG)+1]), CMN = min(MIN[LG][L],MIN[LG][R-(1<<LG)+1]);
    //cout<<MIN[L][LG]<<' '<<MIN[R-(1<<LG)+1][LG]<<endl;
    //cout<<CG<<' '<<CMN<<endl;
    return CG == CMN;
}


