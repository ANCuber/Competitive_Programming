#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include "lib1635.h"
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n = Initialize();    
    if (n == 1) {
        Report(1);
        return 0;
    }
    if (Max(1,2) == 1) {
        Report(1);
        return 0;
    }
    int l = 1, r = n;
    int mid = (l+r)>>1;
    while(r-l > 1) {
        if (Max(mid,mid+1) == mid) r = mid;
        else l = mid;
        mid = (l+r)>>1;
    }
    Report(r);
    return 0;
}
