#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
#include "lib0046.h"
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void Double(int pt) {
    if (pt != 1) return;
    for (int i = 0; i <= 31; ++i) {
        storebit(0,i,1,i);
    }
    calculate(0,1,OP_ADD,2);
    answer(2);
}

void Square() {
    
}

void solve(int pt) {
    if (pt == 1) Double();
    else if (pt == 2) Square();
}
