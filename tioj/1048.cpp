#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'

int f[13] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
char c[12] = {'A','B','C','D','E','F','G','H','I','J','K','L'};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    while(cin>>n>>m && n) {
        bitset <12> v;
        v.reset();
        if (m%f[n] == 0) m = f[n];
        else m %= f[n];
        m--;
        for (int i = n-1; i >= 0; --i) {
            int tmp = m/f[i];
            int j, cnt = -1;
            for (j = 0 ;; ++j) {
                if (v[j]) continue;
                cnt++;
                if (cnt == tmp) break;
            }
            if (i != n-1) cout<<' ';
            cout<<c[j];
            v[j] = 1;
            m %= f[i];
        }
        cout<<endl;
    }
    return 0;
}
