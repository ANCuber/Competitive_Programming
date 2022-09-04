#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int n, m, k, ch; 

int query(int b, vector<int> &fa, vector<int> &cnt) {
    int ret = 0;
    while(b) {
        ret += cnt[b];
        b = fa[b];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    vector<int> fa(n+1,0);
    vector<int> cnt(n+1,0);
    for (int i = 1; i <= n; ++i) {
        cin>>k;
        while(k--) {
            cin>>ch;
            fa[ch] = i;
        }
    }
    int a, b;
    while(m--) {
        cin>>a>>b;
        if (a) {
            cout<<(query(b,fa,cnt)&1)<<endl;
        } else {
            cnt[b]++;
        }
    }
    return 0;
}

