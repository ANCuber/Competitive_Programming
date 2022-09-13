#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;    
    while(cin>>n && n) {
        n = 2*n-1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || (n-i-1) == j || i == n/2 || j == n/2) cout<<'*';
                else cout<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}
