#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
#include "mpi.h"
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    concurrency::parallel_for(0,1e8, [&](){
        int cnt = 0;
        for (int i = 1; i < 2e6; ++i) cnt++;
        cout<<cnt<<' ';
    });
    return 0;
}
