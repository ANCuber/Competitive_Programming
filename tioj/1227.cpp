#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include "lib1227.h"

using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

vector<ll> d[2];
int flag = 0, n;

void init(int _n, ll D[]) {
    n = _n;
    d[0].pb(0);
    d[1].pb(0);
}

void change(int a, int b, ll k) {
    a++,b++;
}

ll query(int c) {
    
}
