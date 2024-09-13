#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

pair<char,char> check() {
    int a = rand()^rand()^44497;
    int b = rand()^rand()^86243;
    char x, y;
    if (a&1) x = '*';
    else x = '-';
    if (b&1) y = '*';
    else y = '-';
    return {x,y};
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    srand(time(NULL));
    /*int cnt = 0, star = 0, minus = 0;
    for (int i = 0; i < 1e6; ++i) {
        pair<char,char> cur = check();
        if (cur.first != cur.second) cnt++;
        else if (cur.first == '*') star++;
        else minus++;
    }
    cout<<cnt<<' '<<star<<' '<<minus<<'\n';*/
    pair<char,char> cur = check();
    cout<<cur.first<<' '<<cur.second<<'\n';
    return 0;
}
