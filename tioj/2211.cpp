#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include "lib2211.h"
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, k, b;
vector<int> v(100005,-1);

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    n = Init();
    b = k = sqrt(n);
    v[1] = 0;
    for (int i = 1; i < k; ++i) v[Query(1,i)] = i;
    while(true) {
        int cur = Query(1,b);
        if (v[cur] >= 0) {
            Report(Query(1,b-v[cur]-1));
            return 0;
        }
        if (b + k > n) {
            for (int i = 1; b+i <= n; ++i) {
                if (Query(1,b+i) == 1) {
                    Report(Query(1,b+i-1));
                }
            }
        }
        b += k;
    }
    return 0;
}
