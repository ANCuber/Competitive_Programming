#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int pow(int x, int n, int y) {
    int ret = 1;
    while(n) {
        if (n&1) ret = (ret*x)%y;
        x = (x*x)%y;
        n >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, n, y;    
    while(cin>>a>>n>>y && (a+n+y)) {
        int cnt = 0;
        for (int i = 0; i < y; ++i) {
            if (!i && !n) continue;
            cnt += (pow(i,n,y) == a);
        }
        cout<<cnt<<endl;;
    }
    return 0;
}
