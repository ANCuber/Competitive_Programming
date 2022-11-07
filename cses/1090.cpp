#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    int n, x; 
    scanf("%d%d",&n,&x);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) scanf("%d",&p[i]);
    sort(p.begin(),p.end());
    int cur = x, num = 0, cnt = 1;
    for (auto i : p) {
        if (num <= 1 && cur >= i) {
            num++;
            cur -= i;
        } else {
            num = 1;
            cnt++;
            cur = x-i;
        }
    }
    printf("%d",cnt);
    return 0;
}
